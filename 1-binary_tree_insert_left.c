#include "binary_trees.h"

/**
 * binary_tree_insert_left - func that inserts a node as
 *                           the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: Ptr to the new node or NULL in case of failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *b_tree;

	if (parent == NULL)
		return (NULL);

	b_tree = binary_tree_node(parent, value);

	if (b_tree == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		b_tree->left = parent->left;
		parent->left->parent = b_tree;
	}
	parent->left = b_tree;

	return (b_tree);
}
