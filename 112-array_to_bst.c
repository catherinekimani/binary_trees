#include "binary_trees.h"

/**
 * array_to_bst - function that builds a BST from an arr
 * @array: pointer to the first elem of the array to be converted
 * @size: number of element in the array
 *
 * Return:  pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t idx;

	for (idx = 0; idx < size; idx++)
		bst_insert(&tree, array[idx]);

	return (tree);
}
