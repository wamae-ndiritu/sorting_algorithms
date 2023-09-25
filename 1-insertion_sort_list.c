#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ASC
 * order using the insertion sort algorithm
 *
 * @list: pointer to pointer to the head of list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current_node = (*list)->next;
	listint_t *back_node;

	while (current_node != NULL)
	{
		back_node = current_node->prev;

		while (back_node != NULL && back_node->n > current_node->n)
		{
			if (back_node->prev != NULL)
				back_node->prev->next = current_node;
			else
				*list = current_node;
			if (current_node->next != NULL)
				current_node->next->prev = back_node;
			back_node->next = current_node->next;
			current_node->prev = back_node->prev;
			current_node->next = back_node;
			back_node->prev = current_node;

			/* Print list after swapping nodes */
			print_list(*list);

			back_node = current_node->prev;
		}
		current_node = current_node->next;
	}
}
