obj-m := ksh_module.o

KDIR := /lib/modules/$(shel uname -r)/build
PWD := $(shell pwd)

dafault:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm	-rf *.ko
	rm	-rf *.mod.*
	rm	-rf .*.cmd
	rm	-rf *.o
	rm	-rf .tmp_versions
