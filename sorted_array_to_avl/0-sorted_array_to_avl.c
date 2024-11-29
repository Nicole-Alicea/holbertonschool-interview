#include "binary_trees.h"
#include <stdlib.h>

/**
 * sorted_array_to_avl_helper - Recursive helper function to build AVL tree
 * @array: Pointer to the first element of the array
 * @start: Start index of the current subarray
 * @end: End index of the current subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the subtree
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end,
avl_t *parent)
{
	int mid;
	avl_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = array[mid];
	node->parent = parent;

	node->left = sorted_array_to_avl_helper(array, start, mid - 1, node);
	node->right = sorted_array_to_avl_helper(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root of the AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}
