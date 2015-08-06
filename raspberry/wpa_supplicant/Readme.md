
# WPA Supplicant [for Raspberry Pi]

Configuration files and scripts for WPA Supplicant [for Raspberry Pi]


Download files to your Pi and rename them:
```
$ sudo cp wpa_supplicant/etc-default-wpa_supplicant /etc/default/wpa_supplicant
$ sudo cp wpa_supplicant/etc-wpa_supplicant-wpa_supplicant.conf /etc/wpa_supplicant/wpa_supplicant.conf 
$ sudo cp wpa_supplicant/etc-init.d-wpa_supplicant /etc/init.d/wpa_supplicant
$ sudo chown root:root /etc/init.d/wpa_supplicant 
$ sudo chmod +x /etc/init.d/wpa_supplicant 
```

Available actions:
```
pi@raspberrypi ~ $ sudo /etc/init.d/wpa_supplicant
Usage: /etc/init.d/wpa_supplicant {start|stop|restart|force-reload|reload|status}
pi@raspberrypi ~ $ sudo /etc/init.d/wpa_supplicant status
[FAIL] wpa_supplicant is not running ... failed!
pi@raspberrypi ~ $ sudo /etc/init.d/wpa_supplicant start
[ ok ] Starting Wireless network management: wpa_supplicant.
pi@raspberrypi ~ $ sudo /etc/init.d/wpa_supplicant status
[ ok ] wpa_supplicant is running.
 '-> wlan0 is UP , IP Address 
pi@raspberrypi ~ $ sudo /etc/init.d/wpa_supplicant status
[ ok ] wpa_supplicant is running.
 '-> wlan0 is UP , IP Address 192.168.1.10/24
pi@raspberrypi ~ $ sudo /etc/init.d/wpa_supplicant stop
[ ok ] Stopping Wireless network management: wpa_supplicant.
pi@raspberrypi ~ $ sudo /etc/init.d/wpa_supplicant status
[FAIL] wpa_supplicant is not running ... failed!
```
