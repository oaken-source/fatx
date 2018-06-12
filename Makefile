
obj-m := fatx.o
fatx-objs := src/fatx.o src/super.o src/mount.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
