#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
int is_complete_recursive(const binary_tree_t *tree, size_t idx, size_t size);


/**
 * binary_tree_size - measure binary tree size
 * @tree: pointer to the root node of the tree
 *
 * Return: tree size, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}

/**
 * is_complete_recursive - helper funcion
 * @tree: pointer to the root node of the tree
 * @idx: node index to check
 * @size: number of nodes in the b_tree
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is incomplete
 *         0 if the tree is NULL
 */
int is_complete_recursive(const binary_tree_t *tree, size_t idx, size_t size)
{
	if (tree == NULL)
		return (1);

	if (idx >= size)
		return (0);

	return (is_complete_recursive(tree->left, 2 * idx + 1, size) &&
		is_complete_recursive(tree->right, 2 * idx + 2, size));
}

/**
 * binary_tree_is_complete - check if b_tree is complete
 * @tree:  pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is incomplete
 *         0 if the tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);
	size = binary_tree_size(tree);
	return (is_complete_recursive(tree, 0, size));
}
