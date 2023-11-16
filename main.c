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
<<<<<<< HEAD
	int i = 0, j = 0, e;
=======
>>>>>>> 8d4e86995b628775b85cc77614c84998061beeb5

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
		if (cmd[0][0] == '\0')
		{
			continue;
		}
<<<<<<< HEAD
		i = 0;
		while (cmd[i])
		{
			if (cmd[i][0] == '\n')
				j = 1;
			if (cmd[i][strlen(cmd[i]) - 1] == '\n')
				cmd[i][strlen(cmd[i]) - 1] = '\0';
			i++;
		}
		if (i - j <= 1)
		{
			e = exec(cmd[0], NULL, line_count);
		}
		else
		{
			e = exec(cmd[0], cmd[1], line_count);
		}
=======
		exec(cmd, line_count);
>>>>>>> 8d4e86995b628775b85cc77614c84998061beeb5
		free(cmd);
		if (e)
			exit(EXIT_FAILURE);
	}
	return (0);
}
