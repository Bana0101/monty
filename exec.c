#include "monty.h"
/**
 * exec - execute command
 *@cmd: command
 *@n: number
 * Return: 0 on sucess.
 */
int exec(char *cmd, ...)
{
	int i;
	va_list args;
	va_start(args, cmd);
	int n = va_arg(args, int);
	int line_number = va_arg(args, int);
	stack_t **node;

	va_end(args);
	*node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	(*node)->n = n;
	instruction_t inst[] = {{"push", _push}, {"pall", _pall}, {NULL, NULL}};
/*
	if (strcmp(cmd, "push") == 0 && n != -1)
	{
		add_dnodeint(head, n);
	}
*/	for (i = 0; inst[i].opcode; i++)
	{
		if (strcmp(cmd, inst[i].opcode) == 0)
			inst[i].f(node, line_number);
	}
	return (0);
}
