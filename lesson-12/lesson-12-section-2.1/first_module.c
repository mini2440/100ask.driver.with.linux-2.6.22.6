#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>

#define log(fmt, arg...) printk(KERN_INFO "[Paul][%s][%d] "fmt"\n", __func__, __LINE__, ##arg);

static int first_open(struct inode *indeo, struct file *file)
{
        log("first drv open ok");
        return 0;
}

static int first_release(struct inode *indeo, struct file *file)
{
        log("first drv release ok");
        return 0;
}

static ssize_t first_read(struct file *file, char __user *buff, size_t cnt, loff_t *loff)
{
        log("first drv read ok");
        return 0;
}

static ssize_t first_write(struct file *file, const char __user *buff, size_t cnt, loff_t *loff)
{
        log("first drv write ok");
        return 0;
}

static struct file_operations fops =
{
        .open    = first_open,
        .release = first_release,
        .read    = first_read,
        .write   = first_write,
};

static int major;

static int __init mod_init(void)
{
        /**
         * 注册一个字符设备
         * 第一个参数为0，表示由系统自动分配主设备号
         * 第二个参数为设备的名称
         *     这个设备名是 /proc/device 节点下对应的名字
         * 第三个参数是设备的读写操作函数
         */
        major = register_chrdev(0, "first_driver", &fops);
        log("mod_init ok, major = %d", major);
        return 0;
}

static void __exit mod_exit(void)
{
        unregister_chrdev(major, "major");
        log("mod_exit ok");
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
