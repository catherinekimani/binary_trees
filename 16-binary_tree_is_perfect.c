#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *tree);
int findDepth(const binary_tree_t *tree);

/**
 * findDepth - find depth of the node
 * @tree: pointer to the head of the tree
 *
 * Return: depth of the tree
 */
int findDepth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree != NULL)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * isPerfectRec - func to check if tree,depth & leve; are perfect
 * @depth: depth of the tree
 * @level: level of the tree
 * @tree: pointer to the head of the tree
 *
 * Return: 1 if True
 */
int isPerfectRec(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	{
		if (depth == level + 1)
			return (1);
		else
			return (0);
	}

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (isPerfectRec(tree->left, depth, level + 1) &&
		isPerfectRec(tree->right, depth, level + 1));
}

/**
     * binary_tree_is_perfect - func that checks if a binary tree is perfect
     * @tree: pointer to the root node of the tree to check
     *
     * Return: 1 if perfect else 0
     */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = findDepth(tree);

	if (tree == NULL)
		return (0);
	return (isPerfectRec(tree, depth, 0));
}
