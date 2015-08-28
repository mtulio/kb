# get_System_Information.sh

Get TCP and Sockets information from your Linux System, and
then, if you set option -s, you can save the current data to a file
See FILE_STDOUT to change filename.
You'll get more if:
	-> run it by super user (eg.: root)
	-> use watch to see in real time and constantly update
	-> schedule, with -s option, in crontab to see logs later (Needs to finish, standarize, the log output)

Network References:
       - See TCP states machine: http://www.tcpipguide.com/free/t_TCPOperationalOverviewandtheTCPFiniteStateMachineF-2.htm


See an sample output running by root [and using watch to refresh data every a second]:
```
[root@mtnote system_socket_information]# watch -n1 ./get_System_Information.sh 
Every 1,0s: ./get_System_Information.sh                                                                            Thu Aug 27 23:04:09 2015

                         .:: GET TCP and Sockets Information ::.

                                TCP Connections
DATE            Count:  Estbli  SYN-Snt SYN-Rcv FIN-W1  FIN-W2  Time-W  Closed  Close-W L-ACK   LISTEN  CLOSING
23:04:09        6	1	0	0	0	0	0	0	0	0	5	0

                                 Sockets Information
                ProcAll System  Kernel  Tcp_All RAW     TCP     UDP     INET    FRAG
                614     854     891     7	3	6	12	21	0


###################################
NOTE: is better using to automatically update, such as: $ watch -n1 ./get_System_Information.sh
 -> Created by Marco Túlio. Enjoy it :)

```


