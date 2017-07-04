ifeq ($(KERNELRELEASE),)
KERNELDIR ?=/root/Desktop/linux-3.0.8
PWD := $(shell pwd)
modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
modules_install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions
.PHONY: modules modules_install clean

else
	obj-m :=key_driver.o
endif
