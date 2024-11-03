#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it
 * @list: Pointer to the head of the list
 * Return: 1 if there is a cycle, 0 if there is no cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *slow = list;
    listint_t *fast = list;

    if (!list)  // Check if the list is empty
        return (0);

    // Traverse the list with two pointers
    while (fast && fast->next)
    {
        slow = slow->next;          // Move slow pointer by one step
        fast = fast->next->next;    // Move fast pointer by two steps

        if (slow == fast)           // If they meet, there is a cycle
            return (1);
    }

    return (0);  // No cycle found
}