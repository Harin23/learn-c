// SPDX-License-Identifier: GPL-2.0
/*
 * learn-c Phase 9 — char device + sysfs stats skeleton (Project 49)
 * Extend completed Project 48 or implement here with DEVICE_ATTR
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/device.h>

#define LEARN_BUFFER_SIZE 4096
#define CLASS_NAME "learn_c"
#define DEVICE_NAME "learn_buffer"

static dev_t dev_num;
static struct cdev learn_cdev;
static struct class *learn_class;
static struct device *learn_device;
static unsigned long read_count;
static unsigned long write_count;
static unsigned int max_buffer_bytes = LEARN_BUFFER_SIZE;

/* TODO: implement circular buffer + fops (copy from Project 48) */

static ssize_t read_count_show(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	return scnprintf(buf, PAGE_SIZE, "%lu\n", read_count);
}

static DEVICE_ATTR_RO(read_count);

static ssize_t write_count_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	return scnprintf(buf, PAGE_SIZE, "%lu\n", write_count);
}

static DEVICE_ATTR_RO(write_count);

static int __init learn_buffer_sysfs_init(void)
{
	int ret;

	ret = alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
	if (ret)
		return ret;

	cdev_init(&learn_cdev, NULL); /* TODO: set learn_fops */
	ret = cdev_add(&learn_cdev, dev_num, 1);
	if (ret)
		goto err_unregister;

	learn_class = class_create(CLASS_NAME);
	if (IS_ERR(learn_class)) {
		ret = PTR_ERR(learn_class);
		goto err_cdev;
	}

	learn_device = device_create(learn_class, NULL, dev_num, NULL, DEVICE_NAME);
	if (IS_ERR(learn_device)) {
		ret = PTR_ERR(learn_device);
		goto err_class;
	}

	ret = device_create_file(learn_device, &dev_attr_read_count);
	if (ret)
		goto err_device;
	ret = device_create_file(learn_device, &dev_attr_write_count);
	if (ret)
		goto err_read_attr;

	pr_info("learn-c: learn_buffer_sysfs loaded\n");
	return 0;

err_read_attr:
	device_remove_file(learn_device, &dev_attr_read_count);
err_device:
	device_destroy(learn_class, dev_num);
err_class:
	class_destroy(learn_class);
err_cdev:
	cdev_del(&learn_cdev);
err_unregister:
	unregister_chrdev_region(dev_num, 1);
	return ret;
}

static void __exit learn_buffer_sysfs_exit(void)
{
	device_remove_file(learn_device, &dev_attr_write_count);
	device_remove_file(learn_device, &dev_attr_read_count);
	device_destroy(learn_class, dev_num);
	class_destroy(learn_class);
	cdev_del(&learn_cdev);
	unregister_chrdev_region(dev_num, 1);
	pr_info("learn-c: learn_buffer_sysfs unloaded\n");
}

module_init(learn_buffer_sysfs_init);
module_exit(learn_buffer_sysfs_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("learn-c student");
MODULE_DESCRIPTION("Char device with sysfs stats skeleton");
