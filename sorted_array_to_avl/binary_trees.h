#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h> /* For size_t */

/* Basic Binary Tree node structure */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* AVL Tree node structure (same as binary tree for now) */
typedef struct binary_tree_s avl_t;

/* Function Prototypes */
avl_t *sorted_array_to_avl(int *array, size_t size);

/* Optional function prototypes (if needed for debugging/printing) */
void binary_tree_print(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */