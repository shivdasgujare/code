#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/moduleparam.h>

static int irq;
static char *interface;

module_param(interface, charp,0);
MODULE_PARM_DESC(interface, "A network interface");
module_param(irq, int, 0);
MODULE_PARM_DESC(irq, "The IRQ of the network interface");

static irqreturn_t myinterrupt(int irq, void *dev_id, struct pt_regs *regs)
{
    static int mycount = 0;

    if (mycount < 10) {
        printk("Interrupt! = %d\n", mycount);
        mycount++;
    }

    return IRQ_NONE;
}

static int __init mymodule_init(void)
{
    printk ("My module worked!\n");
    if (request_irq(irq, &myinterrupt, IRQF_SHARED, interface, &irq)) {
        printk(KERN_ERR "myirqtest: cannot register IRQ %d\n", irq);
        return -EIO;
    }
    printk("Request on IRQ %d succeeded\n", irq);

    return 0;
}

static void __exit mymodule_exit(void)
{
    free_irq(irq, &irq);
    printk("Freeing IRQ %d\n", irq);

    printk ("Unloading my module.\n");
    return;
}

module_init(mymodule_init);
module_exit(mymodule_exit);

MODULE_LICENSE("GPL");
