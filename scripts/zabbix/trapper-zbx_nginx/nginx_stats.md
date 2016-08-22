
# Zabbix Template - NGINX_STAT

Return global stats from Zabbix.

OBS.: The module `nginx_stats.py` depends of lib `zabbix_lib.py` to be available on the [same directory](https://raw.githubusercontent.com/mtulio/kb/master/scripts/zabbix/trapper-zbx_nginx/zabbix_lib.py) of script.

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


## INSTALATION [DEVELOPMENT]

* Download script and its dependencies to Zabbix server

```shell

```

* Configure NGINX virtual host to allow status connections only from zabbix server

```shell

```

* Configure Template on Linux Server 

```shell

```

* Add template to host that will be monitored

* Schedulle the script execution


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




## CONSIDERATIONS:

This script was based on template [zbx_nginx_template](https://github.com/blacked/zbx_nginx_template)
