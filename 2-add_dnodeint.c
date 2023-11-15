#include "lists.h"
/**
 * add_dnodeint - add not at beginning of dlistint_t list
 *@head: head
 *@n: number
 * Return: address of new element
 *
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node;

	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	if (!head || !*head)
	{
		*head = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		node->next = *head;
		node->prev = NULL;
		(*head)->prev = node;
		*head = node;
	}
	return (node);
}
