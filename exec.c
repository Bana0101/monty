#include "monty.h"
/**
 * exec - execute command
 *@cmd: command
 *@n: number
 * Return: 0 on sucess.
 */
int exec(char *cmd, char *num, unsigned int __attribute__((unused)) line_number)
{
	int found = 0;
	int n, i = 0;
	stack_t *node;
	instruction_t inst[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
/*		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
*/		{NULL, NULL}
	};

	while (cmd[i])
	{
		if (cmd[i] == '\n')
			cmd[i] = '\0';
		i++;
	}
	if (strcmp(cmd, "push") == 0)
	{
		if (num == NULL || (atoi(num) == 0 && strlen(num) > 1))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return (1);
		} else
		{
			found = 1;
			n = atoi(num);
			node = malloc(sizeof(stack_t));
			if (node == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				return (1);
			}
			node->n = n;
			inst[0].f(&node, line_number);
		}
	}
	if (strcmp(cmd, "pall") == 0)
	{
		found = 1;
		inst[1].f(NULL, line_number);
	}
	/*
	for (i = 0; inst[i].opcode; i++)
	{
		if (strcmp(inst[i].opcode, cmd) == 0)
		{
			found = 1;
			inst[i].f(&node, line_number);
		}
	}
	*/
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
		return (1);
	}
	return (0);
}
