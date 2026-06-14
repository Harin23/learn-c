// SPDX-License-Identifier: GPL-2.0
/*
 * learn-c Phase 9 — hello LKM starter
 * Complete for Project 47: add module parameter greet_count
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/* TODO Project 47: add int greet_count = 1; module_param(...); MODULE_PARM_DESC(...); */

static int __init hello_lkm_init(void)
{
	pr_info("learn-c: hello_lkm loaded\n");
	return 0;
}

static void __exit hello_lkm_exit(void)
{
	pr_info("learn-c: hello_lkm unloaded\n");
}

module_init(hello_lkm_init);
module_exit(hello_lkm_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("learn-c student");
MODULE_DESCRIPTION("Phase 9 hello LKM starter");
