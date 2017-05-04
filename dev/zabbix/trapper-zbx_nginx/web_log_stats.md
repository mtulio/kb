
# Web log parser

* Default value is return HTTP codes on JSON format
```
$./web_log_stats.py
{"200": 388783, "206": 37, "302": 14216, "304": 60566, "416": 17, "404": 5872, "499": 1610, "400": 400, "500": 1729, "408": 24}

$ ./web_log_stats.py -F json
{"200": 388783, "206": 37, "302": 14216, "304": 60566, "416": 17, "404": 5872, "499": 1610, "400": 400, "500": 1729, "408": 24}

$ ./web_log_stats.py -F json -o code
{"200": 388783, "206": 37, "302": 14216, "304": 60566, "416": 17, "404": 5872, "499": 1610, "400": 400, "500": 1729, "408": 24}

$./web_log_stats.py |python -m json.tool
{
    "200": 388783,
    "206": 37,
    "302": 14216,
    "304": 60566,
    "400": 400,
    "404": 5872,
    "408": 24,
    "416": 17,
    "499": 1610,
    "500": 1729
}

```

* Return data on zabbix trapper format

```
./web_log_stats.py -o code -F json -z 127.0.0.1 -zh example.com -zs cluster1 |python -m json.tool
{
    "data": [
        {
            "clock": "1472403810",
            "host": "example.com",
            "key": "cluster1.http.200",
            "value": 59490
        },
        {
            "clock": "1472403810",
            "host": "example.com",
            "key": "cluster1.http.404",
            "value": 626
        },
        {
            "clock": "1472403810",
            "host": "example.com",
            "key": "cluster1.http.499",
            "value": 1315
        },
        {
            "clock": "1472403810",
            "host": "example.com",
            "key": "cluster1.http.400",
            "value": 1
        },
        {
            "clock": "1472403810",
            "host": "example.com",
            "key": "cluster1.http.502",
            "value": 3
        },
        {
            "clock": "1472403810",
            "host": "example.com",
            "key": "cluster1.http.500",
            "value": 1364
        }
    ],
    "request": "sender data"
}


```
