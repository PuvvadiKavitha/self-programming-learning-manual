#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/io.h>


MODULE_LICENSE("Dual BSD/GPL");

static dev_t g_dev_no;
static int g_major = 0;
static int g_minor = 0;
static struct cdev g_show_cdev;
static int* g_pload = NULL;

static int show_open(struct inode* p_node, struct file* p_f);
static int show_release(struct inode* p_node, struct file* p_f);
static ssize_t show_read (struct file* p_file,  char __user* buffer,  size_t count, loff_t* pos);
static ssize_t show_write (struct file* p_file,  const char __user* buffer, size_t count, loff_t* pos);
static long show_unlocked_ioctl(struct file* p_file, unsigned int cmd, unsigned long count);
static int k_strlen(const char* p_str);
static void init_GPJ2_0(void);
static void led_start(void);
static void led_stop(void);

static struct file_operations g_show_fops = {
    .open = show_open,
    .release = show_release,
    .read = show_read,
    .write = show_write,
    .unlocked_ioctl = show_unlocked_ioctl,
};


static void led_start(void)
{
	unsigned int value = ioread32(g_pload + 1);
	value |= (0x1 << 0);
	iowrite32(value, g_pload + 1);
}

static void led_stop(void)
{
	unsigned int value = ioread32(g_pload + 1);
	value &= ~(0x1 << 0);
	iowrite32(value, g_pload + 1);
}


static void init_GPJ2_0(void)
{
	//Real address map Virtual address
	//LED1 address 
    g_pload = ioremap(0XE0200280, 16);
	printk("g_pload = 0x%X\n", (unsigned int)g_pload);
	
	unsigned int value = ioread32(g_pload);
	
	//set all zeor 0000 = Input
	value &= ~(0x1 << 0);
	value &= ~(0x1 << 1);
	value &= ~(0x1 << 2);
	value &= ~(0x1 << 3);

	//set 0001 = Output
	value |= (0x1 << 0);
	
	iowrite32(value, g_pload);
}

static long show_unlocked_ioctl(struct file* p_file, unsigned int cmd, unsigned long count)
{
	printk("%s:cmd = %d\n", __FUNCTION__, cmd);

	switch (cmd)
	{
		//stop led
		case 0:
			led_stop();
		break;
		//start led
		case 1:
			led_start();
		break;
	}
	return count;
}





static int show_open(struct inode* p_node, struct file* p_f)
{
    printk("%s\n", __FUNCTION__);
    init_GPJ2_0();
    return 0;
}



static int show_release(struct inode* p_node, struct file* p_f)
{
    printk("%s\n", __FUNCTION__);
    return 0;
}



static int k_strlen(const char* p_str)
{
    size_t length = 0;

    while (*p_str++)
        length++;
    
    return length;
}

static ssize_t show_read (struct file* p_file,  char __user* buffer,  size_t count, loff_t* pos)
{
    printk("%s\n", __FUNCTION__);
    char content[] = "Hello User!";
    int number = copy_to_user(buffer, content, k_strlen(content) + 1);
    return number;
}

static ssize_t show_write (struct file* p_file,  const char __user* buffer, size_t count, loff_t* pos)
{
    printk("%s\n", __FUNCTION__);
    char string[200] = {0};
    int number = copy_from_user(string, buffer, count);
    printk("kernel:%s\n", string);
    return number;
}




static int __init hello_init(void)
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

    cdev_init(&g_show_cdev, &g_show_fops);
    g_show_cdev.owner = THIS_MODULE;
    g_show_cdev.ops = &g_show_fops;
    g_show_cdev.dev = g_dev_no;
    g_show_cdev.count = 1;

    cdev_add(&g_show_cdev, g_dev_no, 1);
    return 0;
}

static void __exit hello_exit(void)
{
    printk("%s\n", __FUNCTION__);
    unregister_chrdev_region(g_dev_no, 1);
    cdev_del(&g_show_cdev);
	
	//relese g_pload
	iounmap(g_pload);
    printk("Hello Linux Driver Exit!\n");
}


module_init(hello_init);
module_exit(hello_exit);


