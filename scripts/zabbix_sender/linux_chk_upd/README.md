
# Linux Check Update - linux_chk_upd

* Script based on Template to check updates on OS - based on [this template](https://github.com/Open-Future-Belgium/zabbix/blob/master/check-yum-updates/check-yum-updates.sh).
* Script will check packages on Linux System and report data to zabbix through zabbix-sender.
* Script tested on Linux OS Family Enterprise Linux and Debian.


## Zabbix Template

TODO: Zabbix Template with follow keys - [based template](https://github.com/Open-Future-Belgium/zabbix/tree/master/check-yum-updates):
* 1) repo.moderate : UNSIGNED INTEGER 
* 2) repo.important: UNSIGNED INTEGER
* 3) repo.low      : UNSIGNED INTEGER
* 4) repo.critical : UNSIGNED INTEGER
* 5) repo.release  : STRING

1) 'Moderate Packages' 

* Yum Severity    : Moderate
* Debian Severity : N/A

2) 'Important Packages' 

* Yum Severity    : Moderate
* Debian Severity : All except 'security'

3) 'Low Packages' 

* Yum Severity    : Low
* Debian Severity : N/A

4) 'Critical Packages' 

* Yum Severity    : Critical
* Debian Severity : security

5) 'Critical Packages' 

* String with "OS Name" and "Major Release"


## EXAMPLES

* RHEL 7:
```
# cat /tmp/zabbix-sender.data 
server-rhel7 repo.moderate 42
server-rhel7 repo.important 75
server-rhel7 repo.low 0
server-rhel7 repo.critical 13
server-rhel7 repo.release redhat_7

```

* DEBIAN 5:
```
# ./check-updates.sh 
server-db5 repo.moderate 0
server-db5 repo.important 307
server-db5 repo.low 0
server-db5 repo.critical 81
server-db5 repo.release debian_5

```

* UBUNTU 14.04:
```
# ./check-updates.sh 
server-ub14 repo.moderate 0
server-ub14 repo.important 69
server-ub14 repo.low 0
server-ub14 repo.critical 0
server-ub14 repo.release ubuntu_14.04

```




## NEXT

* [Nagios Plugin - to improve script ](https://exchange.nagios.org/directory/Plugins/Uncategorized/Operating-Systems/Linux/check-debian-packages/details#_ga=1.242082626.134696852.1471371820)
