#include "monty.h"
stack_t *head = NULL;
/**
 * main - Entry point
 *@ac: number of args
 *@av: arguments passed to main
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	FILE *file;
	unsigned int line_count = 0;
	char **cmd, line[200], *format = "stack";
	int e, i;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_count++;
		cmd = split(line, " ");
		if (cmd[0][0] == '\n' || cmd[0][0] == '#')
		{
			for (i = 0; cmd[i] != NULL; i++)
				free(cmd[i]);
			free(cmd);
			continue;
		}
		if (strcmp(cmd[0], "stack\n") == 0 || strcmp(cmd[0],
					"queue\n") == 0 ||
				strcmp(cmd[0], "stack") == 0 ||
				strcmp(cmd[0], "queue") == 0)
		{
			format = _strdup(cmd[0]);
			continue;
		}
		if (strcmp(format, "stack\n") == 0 ||
				strcmp(format, "stack") == 0)
		{
			e = exec(cmd, line_count);
		}
		if (strcmp(format, "queue") == 0 ||
				strcmp(format, "queue\n") == 0)
		{
			e = exec_queue(cmd, line_count);
		}
		for (i = 0; cmd[i] != NULL; i++)
			free(cmd[i]);
		free(cmd);
		if (e)
			exit(EXIT_FAILURE);
	}
	fclose(file);
	free(format);
	free_dlistint(head);
	return (0);
}
