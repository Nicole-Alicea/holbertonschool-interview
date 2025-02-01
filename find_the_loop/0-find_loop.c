#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The address of the node where the loop starts, or NULL if no loop.
 *
 * This function uses Floyd's Cycle Detection Algorithm (Tortoise and Hare).
 * The slow pointer moves one step at a time, while the fast pointer moves
 * two steps at a time. If they meet, a loop is detected. To find the loop's
 * starting node, the slow pointer is reset to the head and both pointers
 * move one step at a time until they meet again.
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) /* Loop detected */
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow); /* Start of the loop */
		}
	}
	return (NULL); /* No loop */
}
