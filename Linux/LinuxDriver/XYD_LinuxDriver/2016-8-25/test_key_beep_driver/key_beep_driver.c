#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/poll.h>
#include <linux/sched.h>

MODULE_LICENSE("Dual BSD/GPL");

#define KEY_TIMER 10

static dev_t g_dev_no;
static int g_major = 0;
static int g_minor = 0;
static struct cdev g_key_cdev;
static struct timer_list g_key_timer;
static int* g_key_pload = NULL;


#if 0
static int* g_pload = NULL;
static int g_beep_state = 0;
static unsigned int g_scan_value = 0;
static int g_scan_flag = 1;

static int show_open(struct inode* p_node, struct file* p_f);
static int show_release(struct inode* p_node, struct file* p_f);
static ssize_t show_read (struct file* p_file,  char __user* buffer,  size_t count, loff_t* pos);
static ssize_t show_write (struct file* p_file,  const char __user* buffer, size_t count, loff_t* pos);
static long show_unlocked_ioctl(struct file* p_file, unsigned int cmd, unsigned long count);
static int k_strlen(const char* p_str);
static void init_GPD0_0(void);
static void	key_timer_handle(unsigned long data);
#endif




static void key_timer_init(void);
static void init_GPH2_X(void);
static void	key_timer_handle(unsigned long data);
static int key_open(struct inode* p_node, struct file* p_f);
static int key_release(struct inode* p_node, struct file* p_f);
static ssize_t key_read (struct file* p_file,  char __user* buffer,  size_t count, loff_t* pos);
unsigned int key_poll(struct file* p_file, struct poll_table_struct* p_poll_table);
static void alloc_dev_number(void);
static void key_cdev_init(void);




static struct file_operations g_show_fops = {
    .open = key_open,
    .release = key_release,
    .read = key_read,
	.poll = key_poll,
    .write = NULL,
    .unlocked_ioctl = NULL,
};

static struct __wait_queue_head g_key_wait_queue;

static int g_key_state[4] = {1, 1, 1, 1};
static int g_pressed[4] = {0};
static int g_key_press = 0;



static void key_timer_init(void)
{
	init_timer(&g_key_timer);	
	g_key_timer.function = &key_timer_handle;
	g_key_timer.expires = jiffies + KEY_TIMER;
	add_timer(&g_key_timer);
}

static void	key_timer_handle(unsigned long data)
{
	unsigned int value = 0;
	int i = 0;	
	int state = 0;
	value = ioread32(g_key_pload + 1);
	
	for (i = 0; i < 4; i++)
	{
		state = value & (0x1 << i);
		//key down
		if (!state)	
		{
			//2
			g_pressed[i]++;
		}
	    //ignore one pulse	
		if (2 == g_pressed[i])
		{
			g_key_state[i] = 0;
			//key real down
			g_key_press = 1;
			wake_up_interruptible((void*)&g_key_wait_queue);
		}
		
		if ((state > 0) && (g_pressed[i] > 0))
		{
			g_pressed[i] = 0;
		}

	}
	g_key_timer.expires = jiffies + KEY_TIMER;
	add_timer(&g_key_timer);
	return;
}


static int key_open(struct inode* p_node, struct file* p_f)
{
    init_GPH2_X();
    key_timer_init();
	init_waitqueue_head((void*)&g_key_wait_queue);
	return 0;
}


static int key_release(struct inode* p_node, struct file* p_f)
{

	return 0;
}


static ssize_t key_read (struct file* p_file,  char __user* buffer,  size_t count, loff_t* pos)
{
	//printk("%s\n", __FUNCTION__);
	int return_num = 0;

	//key no down
	if (!g_key_press)
	{
		//nonblock module
		if (p_file->f_flags & O_NONBLOCK)
		{
			return -EAGAIN;
		}
		//block module
		else
		{
			wait_event_interruptible(g_key_wait_queue, g_key_press);
		}
	}	
	else//key down 
	{
		g_key_press = 0;
		//if succss return 0, otherwise return the number of byte the copy fail
		return_num = copy_to_user(buffer, g_key_state, sizeof(g_key_state));
		memset((void*)g_key_state, 1, sizeof(g_key_state));
	}
	printk("kernel copy_to_user: return_num = %d\n", return_num);
	
	return 4 - return_num;
}


unsigned int key_poll(struct file* p_file, struct poll_table_struct* p_poll_table)
{
	unsigned int mask = 0;
	poll_wait(p_file, &g_key_wait_queue, p_poll_table);
	
	if (g_key_press)
		mask |= POLLIN | POLLRDNORM;

	return mask;
}




/*Init key GPH2_0 - GPH2_3*/
static void init_GPH2_X(void)
{
    g_key_pload = ioremap(0XE0200C40, 32);
	printk("g_key_pload = 0x%X\n", (unsigned int)g_key_pload);
	
	unsigned int value = ioread32(g_key_pload);
	
	int i = 0;	
	for (i = 0; i < 15; i++)
		value &= ~(0x1 << i);
	
	iowrite32(value, g_key_pload);
}


static void alloc_dev_number(void)
{
	alloc_chrdev_region(&g_dev_no, 0, 1, "key driver");
	g_major = MAJOR(g_dev_no);
	g_minor = MINOR(g_dev_no);
    printk("g_major = %d, g_minor = %d\n", g_major, g_minor);
}


static void key_cdev_init(void)
{
    cdev_init(&g_key_cdev, &g_show_fops);
    g_key_cdev.owner = THIS_MODULE;
    g_key_cdev.ops = &g_show_fops;
    g_key_cdev.dev = g_dev_no;
    g_key_cdev.count = 1;
    cdev_add(&g_key_cdev, g_dev_no, 1);
}


static int __init my_key_init(void)
{
   printk("%s\n", __FUNCTION__);
   alloc_dev_number();
   key_cdev_init();
   return 0;
}

static void __exit my_key_exit(void)
{
    printk("%s\n", __FUNCTION__);
    unregister_chrdev_region(g_dev_no, 1);
    cdev_del(&g_key_cdev);
	iounmap(g_key_pload);
	del_timer(&g_key_timer);
    printk("Hello Linux Key Driver Exit!\n");
}


module_init(my_key_init);
module_exit(my_key_exit);


