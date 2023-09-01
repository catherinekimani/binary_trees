#include "binary_trees.h"

/**
 * binary_tree_rotate_right - func that performs a right-rotation on a b_tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);
	/* store left child of the current root */
	new_root = tree->left;
	/* store right child of pivot */
	tmp = new_root->right;
	/* rotation */
	new_root->right = tree;
	tree->left = tmp;

	if (tmp != NULL)
		tmp->parent = tree;

	tmp = tree->parent;
	tree->parent = new_root;
	new_root->parent = tmp;

	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = new_root;
		else
			tmp->right = new_root;
	}
	return (new_root);
}
