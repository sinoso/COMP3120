#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/utsname.h>
static int __init init_ksh(void)
{
	printk("COMP 3120 : KimSeHyeon\n");
	return 0;
}

static void __exit exit_ksh(void)
{
	printk(KERN_INFO "kernel version : %s\n",utsname()->version);
	printk(KERN_INFO "kernel release : %s\n",utsname()->release);
	
}

module_init(init_ksh);
module_exit(exit_ksh);
MODULE_LICENSE("GPL");
