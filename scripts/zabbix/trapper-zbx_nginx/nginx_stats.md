
# Zabbix Template - NGINX_STAT

Return global stats from Zabbix.

## KEYs

Keys required:

* nginx.accepted_connections  : INTEGER
* nginx.body_reading          : INTEGER
* nginx.handled_requests      : INTEGER
* nginx.handled_connections   : INTEGER
* nginx.header_reading        : INTEGER
* nginx.active_connections    : INTEGER
* nginx.keepalive_connections : INTEGER

Keys description:

* nginx.accepted_connections  : Server Accepted Connections
* nginx.body_reading          : Writing Connections
* nginx.handled_requests      : Server Requests Connections
* nginx.handled_connections   : Server Handle Connections
* nginx.header_reading        : Reading Connections
* nginx.active_connections    : Active Connections
* nginx.keepalive_connections : Waiting/Keep aliving Connections



## TESTING

### Getting result from JSON (do not send trapper)

```shell
# python nginx_stats.py -z zabbix.mydomain.com -s nginx.mydomain.com -j  |python -m json.tool
{
    "data": [
        {
            "clock": "1471900006",
            "host": "nginx.mydomain.com",
            "key": "nginx.accepted_connections",
            "value": "81"
        },
        {
            "clock": "1471900006",
            "host": "nginx.mydomain.com",
            "key": "nginx.body_reading",
            "value": "1"
        },
        {
            "clock": "1471900006",
            "host": "nginx.mydomain.com",
            "key": "nginx.handled_requests",
            "value": "46"
        },
        {
            "clock": "1471900006",
            "host": "nginx.mydomain.com",
            "key": "nginx.handled_connections",
            "value": "81"
        },
        {
            "clock": "1471900006",
            "host": "nginx.mydomain.com",
            "key": "nginx.header_reading",
            "value": "0"
        },
        {
            "clock": "1471900006",
            "host": "nginx.mydomain.com",
            "key": "nginx.active_connections",
            "value": "1"
        },
        {
            "clock": "1471900006",
            "host": "nginx.mydomain.com",
            "key": "nginx.keepalive_connections",
            "value": "0"
        }
    ],
    "request": "sender data"
}

```
