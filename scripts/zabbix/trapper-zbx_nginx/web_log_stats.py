#!/usr/bin/python

import urllib2, base64, re, struct, time, socket, sys, datetime, os.path

try:
    import json
except:
    import simplejson as json

import zabbix_lib as zblib 

import time
start = time.time()

## Keys:
# code_2xx
# code_3xx
# code_3xx
# code_4xx
# code_5xx
# rps - req per sec
# rpm - req per min
# rpd - req per day

class Metric(object):
    def __init__(self, host, key, value, clock=None):
        self.host = host
        self.key = key
        self.value = value
        self.clock = clock

    def __repr__(self):
        if self.clock is None:
            return 'Metric(%r, %r, %r)' % (self.host, self.key, self.value)
        return 'Metric(%r, %r, %r, %r)' % (self.host, self.key, self.value, self.clock)


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
        #code = 500
        #print ("sec=[%d]", sec)
        #print ("code=[%d]", code)
        if code in res_code:
            res_code[code] += 1
        else:
            res_code[code] = 1
    
        #rps[sec] += 1

        line = nf.readline()

    nf.close()
    t_for_end = time.time()

def main():

    hostname  = 'nginx-srv'
    app = 'example.com'

    # Nginx log file path
    #nginx_log_file_path = '/var/log/nginx/web-small.log'
    nginx_log_file_path = "/var/log/nginx/" + app + ".log"

    res_code = {}
    read_log_codes(nginx_log_file_path, res_code)
    data_to_send = []

    # Adding the response codes stats to respons
    for t in res_code:
        key = hostname + '.http.' + t
        #data_to_send.append(Metric(hostname, ('http.%s' % t), res_code[t]))
        data_to_send.append(Metric(hostname, key, res_code[t]))
  

    t_for2_end = time.time()

    print zblib.json_out(data_to_send);

    t_end = time.time()

    #print 'init: ', start
    #print 't_for_init: ', t_for_init-start
    #print 't_for_end: ', t_for_end-start
    #print 't_for2_end: ', t_for2_end-start
    #print 't_end: ', t_end-start



if __name__ == "__main__":
    main()

