#include "binary_trees.h"

bst_t *bst_findMinVal(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);

/**
 * bst_findMinVal - finds the minimum value of the BST
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *bst_findMinVal(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;

		else if (parent != NULL)
			parent->right = node->right;

		if (node->right != NULL)
			node->right->parent = parent;

		free(node);

		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;

		else if (parent != NULL)
			parent->right = node->left;

		if (node->left != NULL)
			node->left->parent = parent;

		free(node);
		return (parent == NULL ? node->left : root);
	}

	successor = bst_findMinVal(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - removes a node from a BST recursively.
 * @root: pointer to the root node of the BST to remove a node from.
 * @node: pointer to the current node in the BST.
 * @value: value to remove from the BST.
 *
 * Return: pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));

		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));

		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - func that removes a node from a BST
 * @root: pointer to the root node of the tree
 *        where you will remove a node
 * @value:  value to remove in the tree
 *
 * Return: ptr to the new root node of the tree
 *         after removing the desired value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
