#include "lists.h"

/**
 * reverse_list - Reverses a singly linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;

    while (head != NULL)
    {
        next = head->next;  /* Store the next node */
        head->next = prev;  /* Reverse the current node's pointer */
        prev = head;        /* Move prev forward */
        head = next;        /* Move head forward */
    }
    return prev;  /* New head of the reversed list */
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the list.
 *
 * Return: 1 if the list is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    if (head == NULL || *head == NULL)
        return 1;  /* An empty list is a palindrome */

    listint_t *slow = *head, *fast = *head, *first_half = *head, *second_half = NULL;

    /* Find the middle of the list using the fast and slow pointers */
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse the second half of the list */
    second_half = reverse_list(slow);

    /* Compare the first half and the reversed second half */
    listint_t *temp = second_half;
    while (temp != NULL)
    {
        if (first_half->n != temp->n)
        {
            /* Restore the list before returning */
            reverse_list(second_half);
            return 0;  /* Not a palindrome */
        }
        first_half = first_half->next;
        temp = temp->next;
    }

    /* Restore the list to its original form */
    reverse_list(second_half);

    return 1;  /* It is a palindrome */
}