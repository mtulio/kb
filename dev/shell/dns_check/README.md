
# Name server test

Automatic test in nameserver and domain. You ca use to a quickly tests in domains.


Command line:
```
# ./dns_check.sh <NAMESERVER> <DOMAIN>
```

* Test using nameservers and domains
```
$ NAMESERVERS="8.8.8.8 8.8.4.4"
$ DOMAINS="mtulio.eng.br ict-eng.net"
$ for NS in $NAMESERVERS; do for DOMAIN in $DOMAINS; do ./dns_check.sh $NS $DOMAIN ; done; done
```
