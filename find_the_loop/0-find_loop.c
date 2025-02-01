#include "lists.h"

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
			return slow; /* Start of the loop */
		}
	}
	return NULL; /* No loop */
}
