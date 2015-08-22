# MTulio EngICT
# Description: MTulio API - Driver
# Dependencies: [cross]Linux Kernel
# ARGS:
#	CC : CROS-COMPULE
#	STRIP : STRIP PROGRAM
#	ARCH : BUILD TO ARCHTECTURE (arm, mips, etc)
#	PATH_KERN = Path to Kernel
# 	PATH_INCLUDE = Path to include of this project


CC:= $(CROSS_COMPILE)gcc
STRIP:= $(CROSS_COMPILE)strip
ARCH:= $(ARCH)
PATH_KERN:= $(PATH_KERNEL)
PATH_INCLUDE:= ../include

CFLAGS += -I.
CFLAGS += -I$(PATH_INCLUDE)
CFLAGS += -I$(PATH_KERN)/path/to/kernel/headers/to/include/CHANGE_ME

MODULE_NAME  = mtulio_drv

obj-m    := $(MODULE_NAME).o

$(MODULE_NAME)-objs := mtulio_drv

all:
	@echo "   BUILD module $(MODULE_NAME)"
	make M=$(PWD) -C $(PATH_KERN) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) $(CFLAGS) modules

clean:
	make -C $(PATH_KERN) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD) clean
	rm -rf .tmp_versions/ *.ko *.cmd *.o Module.symvers

