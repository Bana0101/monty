#include "monty.h"

/**
 * _rotl - a function that rotates the stack to the top.
 * @node: unused variable
 * @line_number: unused variable
 * Return: void
 */

void _rotl(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (head != NULL && head->next != NULL)
	{
		last = head;
		while (last->next)
			last = last->next;
		last->next = head;
		head->prev = last;
		head = head->next;
		head->prev = NULL;
		last->next->next = NULL;
	}
}
/**
 * _rotr - a function that rotates the stack to the bottom.
 * @node: unused variable
 * @line_number: unused variable
 * Return: void
 */

void _rotr(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (head != NULL && head->next != NULL)
	{
		last = head;
		while (last->next)
			last = last->next;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = head;
		head->prev = last;
		head = last;
	}
}