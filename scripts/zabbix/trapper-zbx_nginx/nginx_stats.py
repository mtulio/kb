#!/usr/bin/python

import urllib2, base64, re, struct, time, socket, sys, datetime, os.path
import argparse

import zabbix_lib as zblib 

try:
    import json
except:
    import simplejson as json


def get(url, login, passwd):
	req = urllib2.Request(url)
	if login and passwd:
		base64string = base64.encodestring('%s:%s' % (login, passwd)).replace('\n', '')
		req.add_header("Authorization", "Basic %s" % base64string)
	q = urllib2.urlopen(req)
	res = q.read()
	q.close()
	return res

def parse_nginx_stat(data):
	a = {}
        #data_arr = re.split('\n', data)

	# Active connections
	a['active_connections'] = re.match(r'(.*):\s(\d*)', data[0], re.M | re.I).group(2)
	# Accepts
	a['accepted_connections'] = re.match(r'\s(\d*)\s(\d*)\s(\d*)', data[2], re.M | re.I).group(1)
	# Handled
	a['handled_connections'] = re.match(r'\s(\d*)\s(\d*)\s(\d*)', data[2], re.M | re.I).group(2)
	# Requests
	a['handled_requests'] = re.match(r'\s(\d*)\s(\d*)\s(\d*)', data[2], re.M | re.I).group(3)
	# Reading
	a['header_reading'] = re.match(r'(.*):\s(\d*)(.*):\s(\d*)(.*):\s(\d*)', data[3], re.M | re.I).group(2)
	# Writing
	a['body_reading'] = re.match(r'(.*):\s(\d*)(.*):\s(\d*)(.*):\s(\d*)', data[3], re.M | re.I).group(4)
	# Waiting
	a['keepalive_connections'] = re.match(r'(.*):\s(\d*)(.*):\s(\d*)(.*):\s(\d*)', data[3], re.M | re.I).group(6)

	return a


def get_stat(hostname, stat_url, stat_user, stat_pass, metric=False):
    data_to_send = []
    
    data = get(stat_url, stat_user, stat_pass).split('\n')
    data = parse_nginx_stat(data)
    data_to_send = []

    # Adding the metrics to response or print it
    if not metric:
        for i in data:
            #data_to_send.append(Metric(hostname, ('nginx[%s]' % i), data[i]))
            data_to_send.append(zblib.Metric(hostname, ('nginx[%s]' % i), data[i]))
    else:
        return data[metric]

    return data_to_send


def main():

    # Config arguments
    parser = argparse.ArgumentParser()
    parser.add_argument('-z', '--server')
    parser.add_argument('-p', '--port')
    parser.add_argument('-s', '--host')
    parser.add_argument('-u', '--stat-user', dest='stuser', default='none')
    parser.add_argument('-P', '--stat-pass', dest='stpass', default='none')
    parser.add_argument('-m', '--metric')
    parser.add_argument('-S', '--https', action="store_true", default=False)
    parser.add_argument('-j', '--json',
        action="store_true", dest="json", default=False,
        help="show json output, without send to zabbix.")

    # Parsing arguments
    args = parser.parse_args()

    ## Getting arguments
    if args.host :
      hostname = args.host
    else :
      print ("Hostname not found (-s), please try again. See -h option.");
      exit(1)
    
    if args.server :
        zabbix_host = args.server
    else :
        zabbix_host = '127.0.0.1'

    if args.port :
        zabbix_port = args.port
    else :
        zabbix_port = '10051'

    stat_user = args.stuser
    stat_pass = args.stpass

    if args.metric :
        metric = re.match(r'nginx\[(.*)\]', args.metric, re.M | re.I).group(1) or False
    else :
        metric = False
    ## Metric
    #metric = (len(sys.argv) >= 2) and re.match(r'nginx\[(.*)\]', sys.argv[1], re.M | re.I).group(1) or False

    # Get data from Stat for each application
    if args.https :
        stat_url = "https://" + hostname + "/nginx_stat"
    else:
        stat_url = "http://" + hostname + "/nginx_stat"

    #print stat_url
    data_to_send = get_stat(hostname, stat_url, stat_user, stat_pass, metric)

    # Just print metric and quit
    if args.metric:
        print data_to_send
        exit(0);

    # Just print JSON and quit
    if args.json :
        print zblib.json_out(data_to_send);
        exit(0);

    zblib.send_trapper(data_to_send, zabbix_host, zabbix_port)

if __name__ == "__main__":
  main()



