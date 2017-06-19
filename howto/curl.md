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

