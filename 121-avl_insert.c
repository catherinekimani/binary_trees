#include "binary_trees.h"
size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
			    avl_t **new, int value);
/**
 * height - height of the tree
 * @tree: pointer to the root node of the tree
 *        to check
 *
 * Return: 1 if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_h = 0, right_h = 0;

		left_h = tree->left ? 1 + height(tree->left) : 1;
		right_h = tree->right ? 1 + height(tree->right) : 1;
		return ((left_h > right_h) ? left_h : right_h);
	}
	return (0);
}

/**
 * balance - measure balance factor of a b_tree
 * @tree: pointer to the root node of the tree
 *
 * Return: balance factor
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
			    avl_t **new, int value)
{
	int blcfcr;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	blcfcr = balance(*tree);
	if (blcfcr > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);

	else if (blcfcr < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);

	else if (blcfcr > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (blcfcr < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - function that inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 *        for inserting the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
