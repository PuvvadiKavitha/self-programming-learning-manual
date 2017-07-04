#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int g_howmany = 1;
static char* g_pstr = "Hello Linux Driver!";

static int __init hello_init()
{
    int i = 0;
    printk("%s\n", __FUNCTION__);
    for(i = 0; i < g_howmany; i++)
    {
	printk("%s\n", g_pstr);
    }
    return 0;
}


static void __exit hello_exit()
{
    printk("%s\n", __FUNCTION__);
    printk("Hello Linux Driver Exit!\n");
}


module_init(hello_init);
module_exit(hello_exit);
module_param(g_howmany, int, S_IRUGO);
module_param(g_pstr, charp, S_IRUGO);


