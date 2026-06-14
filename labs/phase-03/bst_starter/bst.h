#ifndef BST_H
#define BST_H

typedef struct BstNode {
	int key;
	struct BstNode *left;
	struct BstNode *right;
} BstNode;

BstNode *bst_insert(BstNode *root, int key);
BstNode *bst_search(BstNode *root, int key);
void     bst_inorder(const BstNode *root, void (*visit)(int key));
void     bst_free(BstNode *root);
int      bst_height(const BstNode *root);

#endif /* BST_H */
