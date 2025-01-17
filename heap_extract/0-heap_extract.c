#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * swap_values - Swaps the values of two nodes in the heap.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 *
 * Description: This helper function swaps the integer values
 * stored in two nodes. It does not modify the node structure,
 * only their values.
 */
void swap_values(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * get_last_node - Finds the last node in a level-order traversal.
 * @root: Pointer to the root node of the heap.
 *
 * Return: Pointer to the last node in the heap, or NULL if the heap is empty.
 *
 * Description: This function computes the path to the last node
 * in the heap based on its size and traverses the tree accordingly.
 */
heap_t *get_last_node(heap_t *root)
{
    if (!root)
        return NULL;

    size_t size = binary_tree_size(root); /* Assumes binary_tree_size is implemented */
    size_t path = size >> 1; /* Find the path to the last node */
    heap_t *current = root;

    while (path)
    {
        if (path & 1)
            current = current->right;
        else
            current = current->left;
        path >>= 1;
    }
    return current;
}

/**
 * heapify_down - Restores the Max Binary Heap property by sifting down.
 * @node: Pointer to the root node of the subtree.
 *
 * Description: This function compares the value of the current node
 * with its children. If one of the children has a greater value,
 * it swaps them and continues the process recursively.
 */
void heapify_down(heap_t *node)
{
    if (!node)
        return;

    heap_t *largest = node;

    /* Find the largest value among node, left child, and right child */
    if (node->left && node->left->n > largest->n)
        largest = node->left;
    if (node->right && node->right->n > largest->n)
        largest = node->right;

    /* Swap and recurse if necessary */
    if (largest != node)
    {
        swap_values(node, largest);
        heapify_down(largest);
    }
}

/**
 * heap_extract - Extracts the root value of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node, or 0 if the heap is empty.
 *
 * Description: This function performs the following steps:
 * - Retrieves the value of the root node.
 * - Replaces the root node with the value of the last node.
 * - Removes the last node from the tree.
 * - Restores the Max Binary Heap property using the heapify_down function.
 */
int heap_extract(heap_t **root)
{
    if (!root || !*root) /* Check for an empty heap */
        return 0;

    int root_value = (*root)->n; /* Store the root value */

    /* Get the last node in the heap */
    heap_t *last_node = get_last_node(*root);
    if (!last_node)
        return 0;

    if (last_node == *root) /* If there's only one node */
    {
        free(*root);
        *root = NULL;
        return root_value;
    }

    /* Replace root value with the last node's value */
    (*root)->n = last_node->n;

    /* Remove the last node from the tree */
    if (last_node->parent)
    {
        if (last_node->parent->left == last_node)
            last_node->parent->left = NULL;
        else
            last_node->parent->right = NULL;
    }
    free(last_node);

    /* Restore the heap property */
    heapify_down(*root);

    return root_value;
}
