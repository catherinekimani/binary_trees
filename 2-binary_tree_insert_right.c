#include "binary_trees.h"

/**
 * binary_tree_insert_right - func that inserts a node as the right-child
 *                            of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: Ptr to the new node or NULL in case of failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *b_tree;

	if (parent == NULL)
		return (NULL);

	b_tree = binary_tree_node(parent, value);
	if (b_tree == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		b_tree->right = parent->right;
		parent->right->parent = b_tree;
	}
	parent->right = b_tree;

	return (b_tree);
}
