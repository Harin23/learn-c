// SPDX-License-Identifier: GPL-2.0
/*
 * learn-c Part 9 — circular buffer char device starter
 * Complete read/write/open/release for Project 48
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/device.h>

#define LEARN_BUFFER_SIZE 4096
#define DEVICE_NAME "learn_buffer"

static dev_t dev_num;
static struct cdev learn_cdev;
static char buffer[LEARN_BUFFER_SIZE];
static size_t head;
static size_t tail;
static size_t count;

static int learn_open(struct inode *inode, struct file *filp)
{
	filp->private_data = inode->i_cdev;
	return 0;
}

static int learn_release(struct inode *inode, struct file *filp)
{
	return 0;
}

static ssize_t learn_read(struct file *filp, char __user *user_buf,
			  size_t len, loff_t *off)
{
	/* TODO: read from circular buffer into user_buf via copy_to_user */
	(void)user_buf;
	(void)len;
	(void)off;
	return -ENOSYS;
}

static ssize_t learn_write(struct file *filp, const char __user *user_buf,
			   size_t len, loff_t *off)
{
	/* TODO: copy_from_user into circular buffer */
	(void)user_buf;
	(void)len;
	(void)off;
	return -ENOSYS;
}

static const struct file_operations learn_fops = {
	.owner = THIS_MODULE,
	.open = learn_open,
	.release = learn_release,
	.read = learn_read,
	.write = learn_write,
};

static int __init learn_buffer_init(void)
{
	int ret;

	ret = alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
	if (ret)
		return ret;

	cdev_init(&learn_cdev, &learn_fops);
	ret = cdev_add(&learn_cdev, dev_num, 1);
	if (ret) {
		unregister_chrdev_region(dev_num, 1);
		return ret;
	}

	head = tail = count = 0;
	pr_info("learn-c: learn_buffer major=%d\n", MAJOR(dev_num));
	return 0;
}

static void __exit learn_buffer_exit(void)
{
	cdev_del(&learn_cdev);
	unregister_chrdev_region(dev_num, 1);
	pr_info("learn-c: learn_buffer unloaded\n");
}

module_init(learn_buffer_init);
module_exit(learn_buffer_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("learn-c student");
MODULE_DESCRIPTION("Circular buffer char device starter");
