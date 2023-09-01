#include "binary_trees.h"
/**
 * array_to_avl - function that builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size:  number of element in the array
 *
 * Return:  pointer to the root node of the created AVL tree,
 *          or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t idx1, idx2;

	if (array == NULL)
		return (NULL);

	for (idx1 = 0; idx1 < size; idx1++)
	{
		for (idx2 = 0; idx2 < idx1; idx2++)
		{
			if (array[idx2] == array[idx1])
				break;
		}
		if (idx2 == idx1)
		{
			if (avl_insert(&tree, array[idx1]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
