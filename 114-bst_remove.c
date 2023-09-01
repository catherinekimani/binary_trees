#include "binary_trees.h"

bst_t *bst_findMinVal(bst_t *tree);

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
	bst_t *tmp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);

	else if (value > root->n)
		root->right = bst_remove(root->right, value);

	else
	{
		if (root->left == NULL)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}
		tmp = bst_findMinVal(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}

/**
 * bst_findMinVal - func to fund the minimum value
 * @tree: pointer to the node of the tree
 *
 * Return: NULL if tree is NULL
 */
bst_t *bst_findMinVal(bst_t *tree)
{
	if (tree == NULL)
		return (NULL);
	while (tree->left != NULL)
		tree = tree->left;

	return (tree);
}
