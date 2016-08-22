#!/usr/bin/python

import urllib2, base64, re, struct, time, socket, sys, datetime, os.path

try:
    import json
except:
    import simplejson as json

#################
## Zabbix Trapper Send to Zabbix
def send_trapper(metrics, zabbix_host='127.0.0.1', zabbix_port=10051):

    json_data = json_out(metrics);
    data_len = struct.pack('<Q', len(json_data))
    packet = 'ZBXD\x01'+ data_len + json_data
   
    print json_data;
    return;
    #print packet
    #print ':'.join(x.encode('hex') for x in packet)

    try:
        zabbix = socket.socket()
        zabbix.connect((zabbix_host, zabbix_port))
        zabbix.sendall(packet)
        resp_hdr = sock_recv_all(zabbix, 13)
        if not resp_hdr.startswith('ZBXD\x01') or len(resp_hdr) != 13:
            print 'Wrong zabbix response'
            return False
        resp_body_len = struct.unpack('<Q', resp_hdr[5:])[0]
        resp_body = zabbix.recv(resp_body_len)
        zabbix.close()

        resp = json.loads(resp_body)
        if resp.get('response') != 'success':
            print 'Got error from Zabbix: %s' % resp
            return False
        return True
    except:
        print 'Error while sending data to Zabbix'
        return False


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
## Zabbix OUT

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


def json_out(metrics):
    j = json.dumps
    metrics_data = []
    for m in metrics:
        clock = m.clock or ('%d' % time.time())
        metrics_data.append(('{"host":%s,"key":%s,"value":%s,"clock":%s}') % (j(m.host), j(m.key), j(m.value), j(clock)))

    json_data = ('{"request":"sender data","data":[%s]}') % (','.join(metrics_data))

    return json_data


#zabbix_trapper_send(data_to_send, zabbix_host, zabbix_port)
