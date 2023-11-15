#include "monty.h"
/**
 * exec - execute command
 *@cmd: command
 *@n: number
 * Return: 0 on sucess.
 */
int exec(char cmd, ...)
{
	va_list args;
	va_start(args, cmd);

	int n = va_arg(args, int);
	int line_number = va_arg(args, int);

	va_end(args);


	typedef struct instruction_s inst[] = {{"push", _push()}, {"pall", pall}, {NULL, NULL}};

	if (strcmp(cmd, "push") == 0 && n != -1)
	{
		add_dnodeint(head, n);
	}
	for (i = 0; inst[i]; i++)
	{
		if (strcmp(cmd, inst[i].opcode) == 0)
			inst[i].f()
	return (0);
}
