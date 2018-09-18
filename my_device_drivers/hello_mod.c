#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

static int __init hello_start(void){
	printk(KERN_INFO "Hello! I am Mangal\n");
	return 0;
}

static void __exit hello_exit(void){
	printk(KERN_INFO "Catch you later!!\n");
}

module_init(hello_start);
module_exit(hello_exit);

MODULE_LICENSE("GPL");


