### 12.2.1 字符设备驱动程序框架

1. 写出驱动程序的 open read wirte 函数

2. 定义一个 file_operations，将驱动的操作函数绑定到 file_operations 中

3. 使用 register_chrdev() 向内核注册一个字符设备驱动程序，需要三个参数，分别是  
   主设备号，驱动名称，驱动操作函数的 file_operations  
   值得注意的是，如果主设备传的是0，内核则会自动分配主设备号

4. register_chrdev 谁去调用它？  
   编写一个模块，在模块的入口函数中调用 register_chrdev 函数进行注册

5. 编写 Makefile，编译模块

6. 查看看目前已经加载的设备

       # cat /proc/devices

7. 加载模块

       # insmod first_module.ko
       mod_init ok, major = 252

8. 再次查看已经注册的设备

       # cat /proc/devices
       252 first_driver

   可以看到 252 first_driver 已经注册上来了

9. 执行测试程序

       # ./app
       driver open fail

9. 手动创建节点

       # mknod /dev/xxx c 252 0
       # ./app
       [Paul][first_open][11] first drv open ok
       [Paul][first_read][23] first drv read ok
       [Paul][first_write][29] first drv write ok
       [Paul][first_release][17] first drv release ok
