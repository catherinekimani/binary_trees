#include "binary_trees.h"

int btreeHeight(const binary_tree_t *tree);
void printCurrentLevel(const binary_tree_t *tree,
			int level, void (*func)(int));

/**
 * btreeHeight - height of a binary tree
 * @tree: pointer to the node of the tree
 *
 * Return: tree height
 */
int btreeHeight(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (0);
	left_h = btreeHeight(tree->left);
	right_h = btreeHeight(tree->right);

	if (left_h > right_h)
		return (left_h + 1);
	else
		return (right_h + 1);
}

/**
 * printCurrentLevel - traverse b_tree using level order traversal
 * @tree: pointer to tree
 * @level: level to print
 * @func: func to call each node
 *
 * Return: NULL if func or tree is NULL
 */
void printCurrentLevel(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);

	else if (level > 1)
	{
		printCurrentLevel(tree->left, level - 1, func);
		printCurrentLevel(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - func that goes through a binary tree
 *                          using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 *        The value in the node must be passed as a parameter to this func.
 *
 * Return:
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int idx, height;

	height = btreeHeight(tree);

	if (tree == NULL || func == NULL)
		return;

	for (idx = 0; idx <= height; idx++)
		printCurrentLevel(tree, idx, func);
}
