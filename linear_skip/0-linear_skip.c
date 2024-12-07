#include "search.h"

/**
 * linear_skip - Implements a skip list search with jump size = sqrt of list size.
 * @list: Pointer to the head of the linked skip list to search in.
 * @value: The integer value to search for.
 *
 * Return: Pointer to the node containing the found value, or NULL if not found.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *now;   // Pointer to track the current node during skip traversal.
    skiplist_t *prev;  // Pointer to track the previous node during skip traversal.
    char *msg1 = "Value checked at index";    // Message template for checking a node.
    char *msg2 = "Value found between indexes"; // Message template for indicating search range.

    // If the list is empty, return NULL.
    if (!list)
        return (NULL);

    prev = list;        // Start the search from the head of the list.
    now = list->express; // Initialize `now` to the first express (skip) pointer.

    // Traverse the skip list using express pointers.
    while (now)
    {
        // Print the current node being checked with the skip pointer.
        printf("%s [%lu] = [%d]\n", msg1, now->index, now->n);

        // If the current node's value is greater than or equal to the target value, stop skipping.
        if (now->n >= value)
            break;

        // Move the `prev` pointer to the current `now` node.
        prev = now;

        // If there are no more express pointers, move to the end of the list.
        if (!now->express)
        {
            while (now->next) // Traverse to the end of the list.
                now = now->next;
            break;
        }

        // Move `now` to the next express pointer.
        now = now->express;
    }

    // Print the range where the linear search will take place.
    printf("%s [%lu] and [%lu]\n", msg2, prev->index, now->index);

    // Perform a linear search between `prev` and `now`.
    while (prev && prev->index <= now->index)
    {
        // Print the current node being checked during the linear search.
        printf("%s [%lu] = [%d]\n", msg1, prev->index, prev->n);

        // If the value at the current node matches the target value, return the node.
        if (prev->n == value)
            return (prev);

        // Move to the next node in the list.
        prev = prev->next;
    }

    // If the value is not found, return NULL.
    return (NULL);
}
