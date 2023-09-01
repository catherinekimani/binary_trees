
#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the second node
 * @second: pointer to the second node
 *
 * Return: ptr to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *first_node, *second_node;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);
	first_node = first->parent;
	second_node = second->parent;

	if (first == second_node || !first_node ||
		(!first_node->parent && second_node))
		return (binary_trees_ancestor(first, second_node));

	else if (first_node == second || !second_node ||
		(!second_node->parent && first_node))
		return (binary_trees_ancestor(first_node, second));

	return (binary_trees_ancestor(first_node, second_node));
}
