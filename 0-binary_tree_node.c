#include "binary_trees.h"
/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: pointer to the parent node
 * @value: value to put in the new node
 *
 * Return: Ptr to the new node or NULL in case of failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *b_tree;

	b_tree = malloc(sizeof(binary_tree_t));
	if (b_tree == NULL)
		return (NULL);

	b_tree->n = value;
	b_tree->parent = parent;
	b_tree->left = NULL;
	b_tree->right = NULL;

	return (b_tree);
}
