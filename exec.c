#include "monty.h"
/**
 * exec - execute command
 *@cmd: command
 *@n: number
 * Return: 0 on sucess.
 */
<<<<<<< HEAD
int exec(char *cmd, char *num, unsigned int __attribute__((unused)) line_number)
=======
int exec(char **cmd, unsigned int __attribute__((unused)) line_number)
>>>>>>> 8d4e86995b628775b85cc77614c84998061beeb5
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

<<<<<<< HEAD
	while (cmd[i])
=======
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (strcmp(cmd[0],"push") == 0)
		node->n = atoi(cmd[1]);
	while (cmd[0][i])
>>>>>>> 8d4e86995b628775b85cc77614c84998061beeb5
	{
		if (cmd[0][i] == '\n')
			cmd[0][i] = '\0';
		i++;
	}
	if (strcmp(cmd, "push") == 0)
	{
		if (num == NULL || (atoi(num) == 0 && strlen(num) > 1))
		{
			printf("L<%d>: usage: push integer\n", line_number);
			return (1);
		} else
		{
			found = 1;
			n = atoi(num);
			node = malloc(sizeof(stack_t));
			if (node == NULL)
			{
				printf("Error: malloc failed");
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
<<<<<<< HEAD
		if (strcmp(inst[i].opcode, cmd) == 0)
		{
			found = 1;
=======
		if (strcmp(inst[i].opcode, cmd[0]) == 0)
>>>>>>> 8d4e86995b628775b85cc77614c84998061beeb5
			inst[i].f(&node, line_number);
		}
	}
	*/
	if (!found)
	{
		printf("L<%d>: unknown instruction <%s>\n", line_number, cmd);
		return (1);
	}
	return (0);
}
