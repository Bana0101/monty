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
/*	instruction_t inst[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
*/
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
	/*
	if (strcmp(cmd, "push") == 0)
		_push(&node, line_number);
	if (strcmp(cmd, "pall") == 0)
		_pall(&node, line_number);
		*/
	switch (cmd)
	{
		case "push":
			_push(&node, line_number);
			break;

		case "pall":
			_pall(&node, line_number);
			break;
	}
	return (0);
}
