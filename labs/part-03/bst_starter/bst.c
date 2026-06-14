#include "bst.h"

#include <stdlib.h>

BstNode *bst_insert(BstNode *root, int key)
{
	/* TODO: recursive or iterative insert */
	(void)key;
	return root;
}

BstNode *bst_search(BstNode *root, int key)
{
	(void)key;
	return root;
}

void bst_inorder(const BstNode *root, void (*visit)(int key))
{
	(void)root;
	(void)visit;
}

void bst_free(BstNode *root)
{
	(void)root;
}

int bst_height(const BstNode *root)
{
	if (!root)
		return -1;
	return 0; /* TODO */
}
