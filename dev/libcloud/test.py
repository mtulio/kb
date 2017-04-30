import json

servers = {
  "servers": [
    {
      "name": "server01",
      "ip4_pub": "1.1.1.1",
      "ip6_pub" : "2.2.2.2.",
      "ip4_priv": "3.3.3.3",
      "ip6_priv": "4.4.4.4"
    },
    {
      "name": "server02",
      "ip4_pub": "1.1.1.1",
      "ip6_pub" : "2.2.2.2.",
      "ip4_priv": "3.3.3.3",
      "ip6_priv": "4.4.4.4"
    }
  ]
}


data = {
    'Servers': [ {
       'name' : 'ACME',
       'shares' : 100,
       'price' : 542.23
      }
    ]
}

json_str = json.dumps(servers)

print data

data2 = json.loads(json_str)

# Writing JSON data
with open('test.json', 'w') as f:
     json.dump(data2, f)

# Reading data back
with open('test.json', 'r') as f:
     data3 = json.load(f)

print data3
