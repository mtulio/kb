# gnuplot_from_csv.sh

This script generates an graph from csv file.

Take a look at GNUPLOT configuration file:
```
gplot_generateFromCsv.pg
```


* Example of CSV file - generating it (see script ):
```
# head data.csv 
2015-08-25_00:50:26;7;;;;;;;;;5;;
2015-08-25_00:50:32;7;;;;;;;;;5;;
2015-08-25_00:50:33;7;;;;;;;;;5;;
2015-08-25_00:50:34;7;;;;;;;;;5;;
2015-08-25_00:50:35;7;;;;;;;;;5;;
2015-08-25_00:50:35;7;;;;;;;;;5;;
2015-08-25_00:50:36;7;;;;;;;;;5;;
2015-08-25_00:50:36;7;;;;;;;;;5;;
2015-08-25_00:50:36;7;;;;;;;;;5;;
2015-08-25_00:50:37;7;;;;;;;;;5;;

```
Data showed above represents the follow fields:
```
#DATE_NOW;established;syn-sent;syn-recv;fin-wait-1;fin-wait-2;time-wait;closed;close-wait;last-ack;listen;closing
```


Finally, run it with scripts to generate graphics:
```
$ ./1-get_connection_stats.sh 
$ ls -al data.csv 
-rw-r--r--. 1 root root 884 Ago 25 04:40 data.csv
$ head -n3 data.csv 
2015-08-25_00:50:26;7;;;;;;;;;5;;
2015-08-25_00:50:32;7;;;;;;;;;5;;
2015-08-25_00:50:33;7;;;;;;;;;5;;

$ ./2-gplot_run.sh 

# Grafic generated with success. See data.png

$ ls -l data.png 
-rw-r--r--. 1 root root 7443 Ago 25 04:40 data.png

```


---

FONTE:
* http://www.ibm.com/developerworks/aix/library/au-gnuplot/
