# curl

Yeap, curl deserves an entire file to show it's options

## GET

* Make me serial requests

`X=0; while true; do echo -n "$X ";curl  http://localhost/; echo; let "X++"; done`

* Show me only status code from an request

`curl -o /dev/null -I -sw "%{http_code}" http://localhost/ `

## POST

## PUT

## DELETE

## Custom stdout

1) create the `curl-format.txt` file with these content:

```
  time_namelookup:  %{time_namelookup}\n
      time_connect:  %{time_connect}\n
   time_appconnect:  %{time_appconnect}\n
  time_pretransfer:  %{time_pretransfer}\n
     time_redirect:  %{time_redirect}\n
time_starttransfer:  %{time_starttransfer}\n
                   ----------\n
        time_total:  %{time_total}\n
```

2) Run the command:

```shell
curl -w "@curl-format.txt" -o /dev/null -s https://www.google.com/teste.txt
```
