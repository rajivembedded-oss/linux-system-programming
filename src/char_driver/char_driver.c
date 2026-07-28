#include <linux/module.h>
#include <linux/init.h>

static int __init char_driver_init(void)
{
    printk(KERN_INFO "Character Driver Loaded\n");
    return 0;
}

static void __exit char_driver_exit(void)
{
    printk(KERN_INFO "Character Driver Unloaded\n");
}

module_init(char_driver_init);
module_exit(char_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rajiv");
MODULE_DESCRIPTION("Basic Linux Character Device Driver");