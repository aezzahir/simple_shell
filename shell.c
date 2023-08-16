#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - main function
 * @ac: Arguments Number
 * @argv: Arguments Vector
 * Return: 0 if success
*/

int main(int ac, char **argv)
{
	char *line = NULL, *line_copy = NULL, argv_0[100];
	char **tokens = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	const char *delim = " \n";
	int number_of_tokens = 0;
	int i, exit_status, num_vars = 0;
	(void)ac;
	_strcpy(argv_0, argv[0]);
	while (1)
	{
		prompt();
		linelen = _getline(&line, &linecap, stdin);
		if (linelen == -1)
		{
			_printf("\n");
			return (-1);
		}
		if (strchr(line, ';') != NULL)
			exec_multiple_cmds(line, argv_0, delim);
		line_copy = malloc(sizeof(char) * linelen);
		if (!line_copy)
			memory_allocation_error();
		_strcpy(line_copy, line);
		number_of_tokens = get_number_of_tokens(line, delim);
		tokens = tokenize_input(line_copy, delim, number_of_tokens);

		if (tokens[0] && strcmp(tokens[0], "exit") == 0)
		{
			exit_status = exit_builtin(tokens);
			return (exit_status);
		}
		execmd(tokens, argv_0);
		for (i = 0; tokens[i]; i++)
			free(tokens[i]);
	}
	free(tokens);
	free(line_copy);
	free(line);
}

