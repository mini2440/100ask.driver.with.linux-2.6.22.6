obj-m += first_module.o

KERNEL = /home/user/mini2440/linux-2.6.22.6
SHARE = /home/user/board

all:
	make -C $(KERNEL) M=`pwd` modules
	/home/user/mini2440/gcc-3.4.5-glibc-2.3.6/bin/arm-linux-gcc first_app.c -o app
	rm -rf $(SHARE)/*
	cp -f *.ko $(SHARE)/
	cp -f app $(SHARE)/
	make clean
	clear
	@echo "\033[31m >>>>>> make all successful <<<<<< \033[0m"
clean:
	make -C $(KERNEL) M=`pwd` modules clean
	rm -f app *.symvers
