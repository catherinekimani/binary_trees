#include "binary_trees.h"

int is_bst_helper(const binary_tree_t *tree, int min, int max);

/**
 * is_bst_helper - helper function
 * @tree: pointer to the root node of the tree to check
 * @min: value of the minimum node visitied
 * @max: value of the minimum node visitied
 *
 * Return: 1 if the tree is valid BST, else 0
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		return (is_bst_helper(tree->left, min, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, max));
	}
	return (1);
}

/**
* binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
* @tree: pointer to the root node of the tree to check
*
* Return: 1 if tree is a valid BST, and 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
