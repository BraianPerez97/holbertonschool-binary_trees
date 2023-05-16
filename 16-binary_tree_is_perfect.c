#include "binary_trees.h"

/**
 * binary_tree_depth - calculates the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of the node, or 0 if tree is NULL or tree has no parent
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
	{
		return (0);
	}
	return (1 + binary_tree_depth(tree->parent));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if is perfect, otherwise 0; if is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}

	if (tree->left == NULL || tree->right == NULL)
	{
		return (0);
	}

	if (binary_tree_depth(tree->left) == binary_tree_depth(tree->right) &&
		binary_tree_height(tree->left) == binary_tree_height(tree->right))
	{
		return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
	}

	else
	{
		return (0);
	}
}
