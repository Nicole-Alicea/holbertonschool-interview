#ifndef BINARY_TREES__H
#define BINARY_TREES__H

#include <stddef.h>
#include <stdlib.h>  // For malloc
#include <stdio.h>   // For NULL

/**
 * struct binary_tree_s - Binary tree node structure
 *
 * @n: Integer stored in the node (node's value)
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 *
 * Description: This structure defines a node in a binary tree. Each node
 * stores an integer value and pointers to its parent, left child, and right
 * child nodes.
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);

#endif /* BINARY_TREES__H */