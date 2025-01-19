#include "binary_trees.h"

/**
 * swap - Swap the values of two nodes.
 * @a: First node.
 * @b: Second node.
 */
void swap(heap_t *a, heap_t *b)
{
	int temp = a->n;
	a->n = b->n;

	b->n = temp;
}

/**
 * get_last_node - Gets the last level-order node in the heap.
 * @root: Pointer to the root of the heap.
 *
 * Return: Pointer to the last node.
 */
heap_t *get_last_node(heap_t *root)
{
	if (!root)
		return (NULL);

	heap_t **queue = malloc(1024 * sizeof(heap_t *));
	if (!queue)
		return (NULL);

	int front = 0, back = 0;
	heap_t *last = NULL;

	queue[back++] = root;

	while (front < back)
	{
		heap_t *node = queue[front++];

		last = node;
		if (node->left)
			queue[back++] = node->left;
		if (node->right)
			queue[back++] = node->right;
	}

	free(queue);
	return (last);
}

/**
 * sift_down - Restores the max heap property by sifting down.
 * @node: Node to start sifting down.
 */
void sift_down(heap_t *node)
{
	while (node)
	{
		heap_t *largest = node;
		if (node->left && node->left->n > largest->n)
			largest = node->left;
		if (node->right && node->right->n > largest->n)
			largest = node->right;

		if (largest == node)
			break;

		swap(node, largest);
		node = largest;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: Value stored in the root node, or 0 if the function fails.
 */
int heap_extract(heap_t **root)
{
	if (!root || !(*root))
		return (0);

	heap_t *heap = *root;
	int value = heap->n;

	heap_t *last = get_last_node(heap);
	if (!last)
		return (0);

	if (last == heap) // If there's only one node
	{
		free(heap);
		*root = NULL;
		return (value);
	}

    // Replace the root with the last node
	heap->n = last->n;

    // Remove the last node
	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);

    // Rebuild the heap
	sift_down(heap);

	return (value);
}
