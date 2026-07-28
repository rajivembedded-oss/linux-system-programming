obj-m += hello_driver.o

KDIR := /home/rajiv/WSL2-Linux-Kernel

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean