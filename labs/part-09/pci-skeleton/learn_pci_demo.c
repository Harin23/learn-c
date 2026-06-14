// SPDX-License-Identifier: GPL-2.0
/*
 * learn-c Part 9 — PCI driver skeleton (Project 50)
 * Uses non-matching ID so probe does not bind VM devices by default.
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/pci.h>

#define LEARN_PCI_VENDOR 0xffff
#define LEARN_PCI_DEVICE 0xffff

static int learn_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
	dev_info(&pdev->dev, "learn-c: pci probe (vendor=%#x device=%#x)\n",
		 pdev->vendor, pdev->device);
	return 0;
}

static void learn_pci_remove(struct pci_dev *pdev)
{
	dev_info(&pdev->dev, "learn-c: pci remove\n");
}

static const struct pci_device_id learn_pci_ids[] = {
	{ PCI_DEVICE(LEARN_PCI_VENDOR, LEARN_PCI_DEVICE) },
	{ 0, }
};
MODULE_DEVICE_TABLE(pci, learn_pci_ids);

static struct pci_driver learn_pci_driver = {
	.name = "learn_pci_demo",
	.id_table = learn_pci_ids,
	.probe = learn_pci_probe,
	.remove = learn_pci_remove,
};

static int __init learn_pci_demo_init(void)
{
	int ret;

	ret = pci_register_driver(&learn_pci_driver);
	if (ret)
		return ret;

	pr_info("learn-c: learn_pci_demo driver registered\n");
	return 0;
}

static void __exit learn_pci_demo_exit(void)
{
	pci_unregister_driver(&learn_pci_driver);
	pr_info("learn-c: learn_pci_demo driver unregistered\n");
}

module_init(learn_pci_demo_init);
module_exit(learn_pci_demo_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("learn-c student");
MODULE_DESCRIPTION("PCI driver skeleton for Part 9");
