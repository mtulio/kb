# driver_mtulio - Example of Device Driver

-> In development...

Example of Linux Device driver using sockets ioctl


Roadmap:
* 'hello world' driver using ioctl with functions:
- init: register_chrdev, major, minor
- exit
- ioctl
- struct file_operations
- EXPORT_SYMBOL 
- MODULE_AUTHOR, MODULE_DESCRIPTION, MODULE_LICENSE
* 'hello world' app to send messages/data to daemon and device driver
* 'hello world' Daemon to receive messagens from APP and send/receive to device driver
- Daemon must have init script and config file



