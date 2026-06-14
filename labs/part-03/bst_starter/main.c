#include "bst.h"

#include <stdio.h>

static void print_key(int key)
{
	printf("%d ", key);
}

int main(void)
{
	BstNode *root = NULL;
	int keys[] = { 5, 3, 7, 1, 4, 6, 8 };

	for (size_t i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
		root = bst_insert(root, keys[i]);

	printf("inorder:");
	bst_inorder(root, print_key);
	printf("\nheight=%d\n", bst_height(root));

	bst_free(root);
	return 0;
}
