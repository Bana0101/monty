#include "monty.h"

/**
 * _div - a function that divides the top 2 elements
 * @node: unused variable
 * @line_number: the line number
 * Return: void
 */

void _div(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	} else
	{
		if (head->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		head->next->n /= head->n;
		_pop(NULL, line_number);
	}
}

/**
 * _mul - a function multiplies the second top element with the top element
 * @node: unused variable
 * @line_number: the line number
 * Return: void
 */

void _mul(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		head->next->n *= head->n;
		_pop(&head, line_number);
	}
}

/**
 * _mod - the rest of the division of the second top element by the top element
 * @node: unused variable
 * @line_number: the line number
 * Return: void
 */

void _mod(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (head->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		head->next->n %= head->n;
		_pop(&head, line_number);
	}
}

/**
 * _pchar -  prints the char at the top of the stack
 * @node: unused variable
 * @line_number: the line number
 * Return: void
 */

void _pchar(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((head->n >= 65 && head->n <= 90) || (head->n >= 97 && head->n <= 122))
	{
		printf("%c\n", (char)head->n);
		fflush(stdout);
		return;
	}
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
}
