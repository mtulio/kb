# systemd and their subsystems 

![alt text](https://lcom.static.linuxfound.org/images/stories/41373/Systemd-components.png "Sys")

> Most of these explanations comes from [public articles referenced here](#external-reference), all rights to it. =)


systemd is a Linux initialization system and service manager that includes features like on-demand starting of daemons, mount and automount point maintenance, snapshot support, and processes tracking using Linux control groups. systemd provides a logging daemon and other tools and utilities to help with common system administration tasks.

**The Linux Boot Process and systemd**

Linux requires an initialization system during its boot and startup process. At the end of the boot process, the Linux kernel loads systemd and passes control over to it and the startup process begins. During this step, the kernel initializes the first user space process, the systemd init process with process ID 1, and then goes idle unless called again. systemd prepares the user space and brings the Linux host into an operational state by starting all other processes on the system.

Below is a simplified overview of the entire Linux boot and startup process:

1. The system powers up. 1 The BIOS does minimal hardware initialization and hands over control to the boot loader.
1. The boot loader calls the kernel.
1. The kernel loads an initial RAM disk that loads the system drives and then looks for the root file system.
1. Once the kernel is set up, it begins the systemd initialization system.
1. systemd takes over and continues to mount the host’s file systems and start services.



# Commands

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
# systemctl start [name.service][
# systemctl stop [name.service]
# systemctl restart [name.service]
# systemctl reload [name.service]
$ systemctl status [name.service]
# systemctl is-active [name.service]
$ systemctl list-units --type service --all
```

#### unit files

`systemctl list-unit-files`

`systemctl list-unit-files --type=service`

## systemd-analyze blame

> [Main docummentation page](https://www.freedesktop.org/software/systemd/man/systemd-analyze.html)
### cheatset

```bash
$ systemd-analyze blame
$ systemd-analyze verify [FILES...]
```

* `systemd-analyze blame`

With `systemd-analyze blame` you cal to tshoot the targets bottlenecks on boot.

* `systemd-analyze verify [FILES...]`

You can check de state of an timer target, for example: 

`$ systemd-analyze verify /etc/systemd/system/my-db-backup.timer`


# External reference

* ["What is systemd?" by Linode](https://www.linode.com/docs/quick-answers/linux-essentials/what-is-systemd/)
* ["Understanding and using systemd" by www.linux.com"](https://www.linux.com/learn/understanding-and-using-systemd)

