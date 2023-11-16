#include "monty.h"
/**
 * exec - execute command
 *@cmd: command
 *@n: number
 * Return: 0 on sucess.
 */
int exec(char **cmd, unsigned int __attribute__((unused)) line_number)
{
	int i = 0;
	stack_t *node;
	instruction_t inst[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"nop", _nop},
/*		{"swap", _swap},
		{"add", _add},
*/		{NULL, NULL}
	};

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (strcmp(cmd[0],"push") == 0)
		node->n = atoi(cmd[1]);
	while (cmd[0][i])
	{
		if (cmd[0][i] == '\n')
			cmd[0][i] = '\0';
		i++;
	}
	for (i = 0; inst[i].opcode; i++)
	{
		if (strcmp(inst[i].opcode, cmd[0]) == 0)
			inst[i].f(&node, line_number);
	}
	return (0);
}
