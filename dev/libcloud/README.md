# LibCloud API (INCOMPLETE / DEVELOPMENT)



## Common commands

1. Show array
  JSON data:
  ```
{
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

  ```

  Search:
  `jq '.servers[] rax-api-server.json'`


1. Find for 'server02' atribute

  `jq '.servers[] | select(.name=="server02")' rax-api-server.json`
