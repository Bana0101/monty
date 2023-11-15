#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point
 * ac - number of args
 * av - arguments passed to main
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	FILE *file;
	unsigned int line_number = 0, e;
	char *cmd[100], line[100]; 

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
        {
		line_number++;
		printf("line %d\n", line_number); 
		if (line[0] == '\n')
		{
			printf("blank line\n");
			continue;
		}
		_strtok(line, cmd);
		e = exec(cmd[0], 3, line_number);
	}
/*	printf("%d lines executed.\n", line_number);
*/	(void)e;
	(void)cmd;
	return (0);
}
