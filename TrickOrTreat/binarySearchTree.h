// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
struct binarySearchNode
{
	int key;
	struct binarySearchNode *left, *right;
};

// A utility function to create a new BST node
struct binarySearchNode *newNode(int item)
{
	struct binarySearchNode *temp = (struct binarySearchNode *)malloc(sizeof(struct binarySearchNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct binarySearchNode *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
}

/* A utility function to insert a new node with given key in BST */
struct binarySearchNode* insert(struct binarySearchNode* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}