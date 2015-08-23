# Vagrant first steps 

Vagrant configuration file & script to manage vms (main commands)

* 'Vagrantfile'  has a configuration file to start VMs with different Linux distributions/versions. 
* 'vm_manage.sh' has a main commands to management an VM.

To use it, just follow a few steps:
* Be sure that VirtualBox is installed in your system
* Be sure that vagrant is installed in your system
* Download 'Vagrantfile' and 'vm_manage.sh' 
* Chage VAGRANT_HOME environment in 'vm_manage.sh'
* Type 'vm_manage.sh' start - at once, vagrant will downloada boxes to your system.
* Connect to your VM
* To check available VMs: 'vm_manage.sh list' 
* To connect to an VM: 'vm_manage.sh ssh VM_NAME'

That's it! ;)

---

NOTE:
* If you change VAGRANT_HOME in script, you might to be use vm_manage.sh. Althought you set it in your current session. :)

Roadmap:
* Installation 'how-to'
* Create a box - step-by-step
* Support libvirt - https://github.com/pradels/vagrant-libvirt


---

# [new]BOX - Creating an custom box
* Reference:  https://blog.engineyard.com/2014/building-a-vagrant-box

Softwares to install:
* vim
* yum update -y



