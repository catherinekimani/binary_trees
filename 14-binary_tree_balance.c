#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_height - calcute the height of a b_tree
 * @tree: pointer to the root node
 *
 * Return: height of the tree, else 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	left_h = 0;
	right_h = 0;

	if (tree == NULL)
		return (0);
	left_h += 1 + binary_tree_height(tree->left);
	right_h += 1 + binary_tree_height(tree->right);

	if (left_h > right_h)
		return (left_h);
	else
		return (right_h);
}

/**
 * binary_tree_balance - func that measures the balance factor of a b_tree
 * @tree:  pointer to the root node of the tree to measure the balance factor
 *
 * Return: 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	return (left_h - right_h);
}
