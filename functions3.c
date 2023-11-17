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
