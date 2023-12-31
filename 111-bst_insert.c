#include "binary_trees.h"

/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the val
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;

	if (tree == NULL || *tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}
	current = *tree;

	while (current != NULL)
	{
		if (current->n == value)
			return (NULL);

		if (current->n > value)
		{
			if (current->left == NULL)
			{
				current->left = binary_tree_node(current, value);
				return (current->left);
			}
			current = current->left;
		}
		if (current->n < value)
		{
			if (current->right == NULL)
			{
				current->right = binary_tree_node(current, value);
				return (current->right);
			}
			current = current->right;
		}
	}
	return (NULL);
}
