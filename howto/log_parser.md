# Web 

## Get RPS frmo access

 `grep "15/Nov/2017:20" /var/log/apache2/marabraz-access.log | cut -d[ -f2 | cut -d] -f1 | awk -F: '{print $2":"$3}' | sort -nk1 -nk2 | uniq -c | awk '{ if ($1 > 10) print $0}'`
