#include "monty.h"
/**
 * exec - execute command
 *@cmd: command
 *@n: number
 * Return: 0 on sucess.
 */
int exec(char *cmd, int n, unsigned int __attribute__((unused)) line_number)
{
	int i = 0;
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

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	while (cmd[i])
	{
		if (cmd[i] == '\n')
			cmd[i] = '\0';
		i++;
	}
	for (i = 0; inst[i].opcode; i++)
	{
		if (strcmp(inst[i].opcode, cmd) == 0)
			inst[i].f(&node, line_number);
	}
	return (0);
}
