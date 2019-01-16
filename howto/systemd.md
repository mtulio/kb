# systemd and their subsystems 

![alt text](https://lcom.static.linuxfound.org/images/stories/41373/Systemd-components.png "Sys")


## systemctl

### Unit Types

* `service`: System services
* `target`: group of units
* `automount`: filesystem auto-mountpoint
* `device`: kernel device names, which you can see in sysfs and udev
* `mount`: filesystem mountpoint
* `path`: file or directory
* `scope`: external processes not started by systemd
* `slice`: a management unit of processes
* `socket`: IPC (inter-process communication) socket
* `swap`: swap file
* `timer`: systemd timer.
* Snapshot: systemd saved state

### cheatset

```bash
# systemctl start [name.service]
# systemctl stop [name.service]
# systemctl restart [name.service]
# systemctl reload [name.service]
$ systemctl status [name.service]
# systemctl is-active [name.service]
$ systemctl list-units --type service --all
# systemd-analyze blame
```

#### unit files

`systemctl list-unit-files`

`systemctl list-unit-files --type=service`

#### systemd-analyze blame

With `systemd-analyze blame` you cal to tshoot the targets bottlenecks on boot.

# External reference

* https://www.linux.com/learn/understanding-and-using-systemd
