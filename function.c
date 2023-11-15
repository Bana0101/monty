#include "monty.h"

/**
 * _push - a function that push an element to the stack
 * @node: the node to be added
 * @line_number: unused variable
 * Return: void
 */

void _push(stack_t **node, unsigned int __attribute__((unused)) line_number)
{
	stack_t *ptr;

	if (head == NULL)
		head = *node;
	else
	{
		ptr = head;
		(*node)->next = ptr;
		ptr->prev = *node;
		head = *node;
	}
}

/**
 * _pall - a function that prints all the values on the stack
 * @line_number: unused variable
 * node: the top of the stack
 * Return: void
 */


void _pall(stack_t **node, unsigned int __attribute__((unused)) line_number)
{
	stack_t *ptr;

	(void)node;
	if (head == NULL)
		printf("Underflow!\n");
	else
	{
		ptr = head;
		while (ptr)
		{
			printf("%d\n",ptr->n);
			ptr = ptr->next;
		}
	}
}
