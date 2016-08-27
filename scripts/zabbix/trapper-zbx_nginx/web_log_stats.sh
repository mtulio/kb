
time cat /var/log/nginx/access.log |awk -F'300] ' '{print$2}' |awk '{print$4" "$1}'  |tr -d '"' |sort |uniq -c |sort -n
