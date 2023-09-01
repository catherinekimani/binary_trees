#include "binary_trees.h"

void sata_helper(avl_t **root, int *array, size_t low, size_t high);

/**
 * sata_helper - helper that builds an AVL tree from an arr
 * @root: double ptr to the root node of the subtree
 * @low: lower bound idx
 * @high: upper bound idx
 * @array: pointer to the first element of the array to be converted
 *
 */
void sata_helper(avl_t **root, int *array, size_t low, size_t high)
{
	avl_t *new = NULL;
	size_t middle;

	if (high - low > 1)
	{
		middle = (high - low) / 2 + low;
		new = binary_tree_node(*root, array[middle]);
		if (array[middle] > (*root)->n)
			(*root)->right = new;
		else if (array[middle] < (*root)->n)
			(*root)->left = new;
		sata_helper(&new, array, low, middle);
		sata_helper(&new, array, middle, high);
	}
}

/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created AVL tree
 *         or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t middle;

	if (!array)
		return (NULL);
	middle = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[middle]);
	sata_helper(&tree, array, -1, middle);
	sata_helper(&tree, array, middle, size);

	return (tree);
}
