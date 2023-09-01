#include "binary_trees.h"

/**
 * binary_tree_rotate_left - func that performs a left-rotation on a b_tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	/* store right child of the current root */
	new_root = tree->right;
	/* store left child of pivot */
	tmp = new_root->left;
	/* rotation */
	new_root->left = tree;
	tree->right = tmp;
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
