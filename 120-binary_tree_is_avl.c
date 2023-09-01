#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int min, int max);

/**
 * height - height of the tree
 * @tree: pointer to the root node of the tree
 *        to check
 *
 * Return: 1 if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_h = 0, right_h = 0;

		left_h = tree->left ? 1 + height(tree->left) : 1;
		right_h = tree->right ? 1 + height(tree->right) : 1;
		return ((left_h > right_h) ? left_h : right_h);
	}
	return (0);
}

/**
 * is_avl_helper - helper function
 * @tree: pointer to the root node of the tree to check
 * @min: value of the smallest node visited
 * @max: value of the largest node visited
 *
 * Return: 1 if tree is a valid AVL else 0
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	size_t left_h, right_h, diff;

	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);

		left_h = height(tree->left);
		right_h = height(tree->right);

		diff = left_h > right_h ? left_h - right_h : right_h - left_h;

		if (diff > 1)
			return (0);

		return (is_avl_helper(tree->left, min, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, max));

	}
	return (1);
}

/**
 * binary_tree_is_avl - func that checks if a binary tree is
 *                      a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
