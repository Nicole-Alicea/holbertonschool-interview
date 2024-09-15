#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node
 * @parent: Pointer to the parent node of the node to be created
 * @value: Value to be stored in the new node
 *
 * Description: This function allocates memory for a new binary tree node
 * and initializes its value, parent, left, and right pointers. The left and
 * right pointers are set to NULL since the new node does not have any children
 * when created. The function returns a pointer to the newly created node or
 * NULL if memory allocation fails.
 *
 * Return: Pointer to the new node or NULL if allocation fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    /* Allocates memory for the new node */
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

    if (!new_node)
        return (NULL);  /* Returns NULL if memory allocation fails */

    /* Sets the value and pointers for the new node */
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);  /* Returns the newly created node */
}
