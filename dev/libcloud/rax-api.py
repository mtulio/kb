
class Server(object):
    name=None
    ip4_pub=None
    ip6_pub=None
    ip4_priv=None
    ip6_priv=None

    def __init__(self, name,
        ip4_priv, ip4_pub,
        ip6_priv, ip6_pub):

        self.name = name
        self.ip4_priv = ip4_priv
        self.ip4_pub = ip4_pub
        self.ip6_priv = ip6_priv
        self.ip6_pub = ip6_pub

import json
file_json_server = 'rax-api-server.json'
file_json_server = 'test.json'
servers = json.load(file_json_server)

print servers
