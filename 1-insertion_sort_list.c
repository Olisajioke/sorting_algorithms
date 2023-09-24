#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Insertion sort
 *
 * @list: Pointer to the pointer of the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (!list || !(*list) || !((*list)->next))
		return;

	listint_t *current, *temp;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;

		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			/* Swap the nodes */
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;

			print_list(*list);
		}

		current = current->next;
	}
}
