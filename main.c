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
	unsigned int line_count = 0;
	char **cmd, line[200];
	int i = 0;

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
		line_count++;
		cmd = split(line, " ");
		if (cmd[0][0] == '\n')
		{
			free(cmd);
			continue;
		}
		i = 0;
		while (cmd[i++])
			;
		if (i <= 2 && strcmp(cmd[1], "\n") == 0)
		{
			printf("im in the 1\n");
			exec(cmd[0], 0, line_count);
		}
		else
		{
			printf("im in the 2\n");
			exec(cmd[0], atoi(cmd[1]), line_count);
		}
		free(cmd);
	}
	return (0);
}
