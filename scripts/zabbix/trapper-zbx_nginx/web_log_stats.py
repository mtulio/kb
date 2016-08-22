#!/usr/bin/python

import urllib2, base64, re, struct, time, socket, sys, datetime, os.path

try:
    import json
except:
    import simplejson as json

import zabbix_lib as zblib 

# Nginx log file path
nginx_log_file_path = '/var/log/nginx/web-small.log'

# Temp file, with log file cursor position
seek_file = '/tmp/nginx_log_stat'

time_delta = 1              # grep interval in minutes
hostname  = 'eu.com'

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

def read_seek(file):
    if os.path.isfile(file):
        f = open(file, 'r')
        try:
            result = int(f.readline())
            f.close()
            return result
        except:
            return 0
    else:
        return 0

def write_seek(file, value):
    f = open(file, 'w')
    f.write(value)
    f.close()


#print '[12/Mar/2014:03:21:13 +0400]'

d = datetime.datetime.now()-datetime.timedelta(minutes=time_delta)
minute = int(time.mktime(d.timetuple()) / 60)*60
d = d.strftime('%d/%b/%Y:%H:%M')

total_req = 0
rps = [0]*60
tps = [0]*60
res_code = {}

nf = open(nginx_log_file_path, 'r')

new_seek = seek = read_seek(seek_file)

# if new log file, don't do seek
if os.path.getsize(nginx_log_file_path) > seek:
    nf.seek(seek)

line = nf.readline()
while line:

    new_seek = nf.tell()
    total_req += 1
    #sec = int(re.match('(.*):(\d+):(\d+):(\d+)\s', line).group(4))
    code = re.match(r'(.*)"\s(\d*)\s', line).group(2)
    #print ("sec=[%d]", sec)
    #print ("code=["+ code +"]")
    if code in res_code:
        res_code[code] += 1
    else:
        res_code[code] = 1
    
    #rps[sec] += 1

    line = nf.readline()

#if total_rps != 0:
#    write_seek(seek_file, str(new_seek))

nf.close()

metric = (len(sys.argv) >= 2) and re.match(r'nginx\[(.*)\]', sys.argv[1], re.M | re.I).group(1) or False

data_to_send = []

# Adding the metrics to response
#if not metric:
#    for i in data:
#        data_to_send.append(Metric(hostname, ('nginx[%s]' % i), data[i]))
#else:
#    print data[metric]

# Adding the request per seconds to response
#rps_sum = 0
#for t in range(0,60):
#    data_to_send.append(Metric(hostname, 'nginx[rps]', rps[t], minute+t))
#    rps_sum += rps[t]

rpm = total_req / 60
data_to_send.append(Metric(hostname, 'nginx.rpm', rpm))

# Adding the response codes stats to respons
for t in res_code:
    data_to_send.append(Metric(hostname, ('nginx.code_%s' % t), res_code[t]))


#print data_to_send
print zblib.json_out(data_to_send);
#print res_code;

## Keys
# code_2xx
# code_3xx
# code_3xx
# code_4xx
# code_5xx
# rpm




