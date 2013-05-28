/*  
 *  helloworld.c - Demonstrating the module_init() and module_exit() macros.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */

static int __init helloworld_init(void)
{
	printk(KERN_INFO "Hello, world 2\n");
	return 0;
}

static void __exit helloworld_exit(void)
{
	printk(KERN_INFO "Goodbye, world 2\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);
