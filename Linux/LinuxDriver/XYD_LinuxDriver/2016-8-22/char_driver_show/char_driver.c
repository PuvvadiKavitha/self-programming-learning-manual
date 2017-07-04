#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("Dual BSD/GPL");

static dev_t g_dev_no;

static int g_major = 0;
static int g_minor = 0;


static int __init hello_init()
{
    if (g_major > 0)
    {
	g_dev_no = MKDEV(g_major, g_minor);
	register_chrdev_region(g_dev_no, 1, "Hello");
    }
    else
    {
	alloc_chrdev_region(&g_dev_no, 0, 1, "Hello");
	g_major = MAJOR(g_dev_no);
	g_minor = MINOR(g_dev_no);
   	
    }
	printk("g_major = %d, g_minor = %d\n", g_major, g_minor);
    printk("%s\n", __FUNCTION__);
    return 0;
}


static void __exit hello_exit()
{
    printk("%s\n", __FUNCTION__);
    unregister_chrdev_region(g_dev_no, 1);
    printk("Hello Linux Driver Exit!\n");
}


module_init(hello_init);
module_exit(hello_exit);


