#!/usr/bin/python
#
# Functions to manipulate data from/to Zabbix Trapper.
# https://github.com/mtulio/kb/blob/master/scripts/zabbix/trapper-zbx_nginx/zabbix_lib.py
#

import re, struct, time, socket, sys, datetime, os.path

try:
    import json
except:
    import simplejson as json

#################################
## Zabbix Trapper Send to Zabbix
def send_trapper(metrics, zabbix_host='127.0.0.1', zabbix_port=10051, log_msg='local - '):

    json_data = json_out(metrics);
    data_len = struct.pack('<Q', len(json_data))
    HEADER = '''ZBXD\1%s%s'''

    data_length = len(json_data)
    data_header = struct.pack('i', data_length) + '\0\0\0\0'
    data_to_send = HEADER % (data_header, json_data)

    zabbix = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    zabbix.connect((zabbix_host, zabbix_port))
    zabbix.send(data_to_send)

    response_header = zabbix.recv(5)
    if not response_header == 'ZBXD\1':
        raise ValueError('Got invalid response')

    response_data_header = zabbix.recv(8)
    response_data_header = response_data_header[:4] # we are only interested in the first four bytes
    response_len = struct.unpack('i', response_data_header)[0]
    response_raw = zabbix.recv(response_len)
    zabbix.close()

    resp = json.loads(response_raw)
    if resp.get('response') != 'success':
        print ("%s Error - got from Zabbix: %s", log_msg, resp)
        return False
    else:
        print ("%s SUCCESS : %s ", log_msg, resp)

    return True
###################################################
def send(data_to_send, z_server='127.0.0.1', z_port=10051):

    if not data_to_send :
        return False

    send_trapper(data_to_send)

def ping():
    #print 'pong'
    return True

# Socket
def sock_recv_all(sock, count):
    buf = ''
    while len(buf)<count:
        chunk = sock.recv(count-len(buf))
        if not chunk:
            return buf
        buf += chunk
    return buf

#################

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

#######################
## Zabbix OUT
def json_out(metrics):
    j = json.dumps
    metrics_data = []
    for m in metrics:
        clock = m.clock or ('%d' % time.time())
        metrics_data.append(('{"host":%s,"key":%s,"value":%s,"clock":%s}') % (j(m.host), j(m.key), j(m.value), j(clock)))

    json_data = ('{"request":"sender data","data":[%s]}') % (','.join(metrics_data))

    return json_data

