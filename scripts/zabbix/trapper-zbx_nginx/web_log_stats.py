#!/usr/bin/python
#
# Script to parser WEB log and show statistics.
# Author: Marco Tulio R Braga <>
# https://github.com/mtulio/kb/blob/master/scripts/zabbix/trapper-zbx_nginx/web_log_stats.py
#


import urllib2, base64, re, struct, time, socket, sys, datetime, os.path, argparse
import time

try:
    import json
except:
    import simplejson as json

try: 
    import zabbix_lib as zblib 
    lib_err_zbx = False
except: 
    lib_err_zbx = True

#############################################
class WebStat(object):
    def __init__(self, name, key, value1, value2, value3):
        self.host = host
        self.key = key
        self.value = value
        self.clock = clock

    def __repr__(self):
        if self.clock is None:
            return 'Metric(%r, %r, %r)' % (self.host, self.key, self.value)
        return 'Metric(%r, %r, %r, %r)' % (self.host, self.key, self.value, self.clock)


#############################################
# Config arguments
parser = argparse.ArgumentParser(description='Web log parser, then can return in JSON and/or send to Zabbix.')

parser.add_argument('-o', '--option', dest='option', default='all',
	help="options to return. [code|method|pages|code_method|all]. Default: all")
parser.add_argument('-t', '--time', dest='time', default='all',
	help="time to return: last [hour|day|all]. Default: all")
parser.add_argument('-F', '--format', dest='format', default='json',
	help="output format: [json|text|html|none|file]. Default: json")
parser.add_argument('-O', '--output', dest='output', default='stdout',
	help="output file: [stdout|filename]. Default: stdout")
parser.add_argument('-f', '--log-file', dest='log_file', default='/var/log/nginx/access.log',
	help="input web log file. Default: /var/log/nginx/access.log")
parser.add_argument('-z', '--zabbix', dest='zabbix', default=False,
	help="zabbix server hostname or IP to enable send through trapper. Default: 127.0.0.1")
parser.add_argument('-zp', '--zabbix-port', dest='z_port', default=10051,
	help="zabbix server trapper port. Default: 10051")
parser.add_argument('-zh', '--zabbix_host', dest='z_host', default=False,
	help="zabbix host to destination data. Default: 'none'")
parser.add_argument('-zs', '--zabbix_sender', dest='z_sender', default=False,
	help="zabbix sender hostname [cluster name]. Default: 'none'")
parser.add_argument('-r', '--resume', dest='resume', default=False,
	help="enable resume, time tooked. Default: False")

# Parse arguments
args = parser.parse_args()

######################################
# Zabbix parser
def parse2zbx_codes(data = {}, data_to_send = []):
    
    # Adding the response codes stats to respons
    for d in data:
        key = args.z_sender + '.http.' + d
        data_to_send.append(zblib.Metric(args.z_host, key, data[d]))
  

def parse2zbx(data = {}):
    
    data_to_send = []
    if args.option == 'code':
        parse2zbx_codes(data, data_to_send)

    return data_to_send

#######################################################
def read_log_codes(nginx_log_file_path, res_code = {}):

    # Compile Regex rule (improved about 20% of time)
    prog = re.compile(r'(.*)"\s(\d*)\s')

    t_for_init = time.time()
    total_req = 0

    nf = open(nginx_log_file_path, 'r')
    line = nf.readline()
    while line:

        new_seek = nf.tell()
        total_req += 1
        #sec = int(re.match('(.*):(\d+):(\d+):(\d+)\s', line).group(4))
        #code = re.match(r'(.*)"\s(\d*)\s', line).group(2)
        #line = line.split('"', 2)
        code = prog.match(line).group(2)
        if code in res_code:
            res_code[code] += 1
        else:
            res_code[code] = 1
    
        line = nf.readline()

    nf.close()
    t_for_end = time.time()
    #t_end = time.time()

    #print 'init: ', start
    #print 't_for_init: ', t_for_init-start
    #print 't_for_end: ', t_for_end-start
    #print 't_for2_end: ', t_for2_end-start
    #print 't_end: ', t_end-start


def get_http_codes():

    nginx_log_file_path = args.log_file
    res_code = {}
    read_log_codes(nginx_log_file_path, res_code)

    return res_code

def data_get():
    global args

    # check options to get
    if args.option == 'code':
        return get_http_codes()

    # Actions

    return 'none'
    #return 'get_data'

###################################
# Show data 
def data_show(data = {}):
    global args

    # Check data to return
    if args.format == 'json' and args.zabbix != False:
       print zblib.json_out(data);
    elif args.format == 'json':
       show_data_json(data);
    elif args.format == 'html':
       show_data_html(data);

    return True

def show_data_json(data = {}):
    if data != {}:
       print json.dumps(data)

def show_data_html(data = {}):
    if data != {}:
       data_html = '<table border="1" class="dataframe">'
       data_html += '<thead><tr style="text-align: right;"><th>KEY</th><th>VALUE</th></tr></thead><tbody>'
       for i in data :
           data_html += '<tr><th>' + i + '</th><th>' + str(data[i]) + '</th></tr>'

       data_html += '  </tbody></table>'
       print data_html

###################################
def data_action(data = {}):

    # Do something: send2zabbix, save2file
    if args.zabbix:
        return zblib.send(parse2zbx(data))

    # Show
    data_show(data)

############################################## 
## 
# -o code|method|pages|code_method|all|rps|rpm|rpd
# -t hour|day|all
# -O json|text|html|none|file
# --output filename
# -l log file
# -z zabbix_server
# -r show resume
## Keys:
# code_2xx
# code_3xx
# code_3xx
# code_4xx
# code_5xx
# rps - req per sec
# rpm - req per min
# rpd - req per day


def main():

    # Check dependencies

    ## Zabbix Lib: https://github.com/mtulio/kb/blob/master/scripts/zabbix/trapper-zbx_nginx/zabbix_lib.py
    if args.zabbix :
        if lib_err_zbx :
            print 'Error : zabbix lib [zabbix_lib.py] not found'
            exit(1);
        if not args.z_host :
            print 'Error : zabbix host not found. Set --zabbix-host'
            exit(1);
        if not args.z_sender:
            print 'Error : zabbix sender not found. Set --zabbix-sender'
            exit(1);
        if not args.z_port:
            z_port = 10051
        else:
            z_port = args.z_port
        if not args.zabbix :
            z_server = '127.0.0.1'
        else:
            z_server = args.zabbix

    if not os.path.isfile(args.log_file):
        print 'File not found: ' + args.log_file
        exit(1);

    return data_action(data_get())

if __name__ == "__main__":
    main()

