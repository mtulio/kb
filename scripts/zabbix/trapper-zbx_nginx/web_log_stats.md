
# Web log parser



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
