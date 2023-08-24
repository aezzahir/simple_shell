#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - main function
 * @ac: Arguments Number
 * @argv: Arguments Vector
 * Return: 0 if success, -1 on failure.
 */
int main(int ac, char **argv)
{
	char *line = NULL, *shell_name = NULL;
	char **tokens = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	const char *delim = " \n";
	int i, cmd_status = 0;
	(void)ac;

	shell_name = malloc(_strlen(argv[0]) + 1);
	if (shell_name == NULL)
		exit(EXIT_FAILURE);
	_strcpy(shell_name, argv[0]);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		linelen = _getline(&line, &linecap, stdin);
		if (linelen == -1)
		{
			if (isatty(STDIN_FILENO))
				_printf("\n");
			break;
		}
		if (_strchr(line, ';') != NULL)
		{
			exec_multiple_cmds(line, delim, shell_name);
			continue;
		}
		tokens = get_tokens(line, delim);
		if (tokens[0])
		{
			if (_strcmp(tokens[0], "exit") == 0)
			{
				cmd_status = exit_builtin(tokens);
				break;
			}
			else
			{
				cmd_status = execmd(tokens, shell_name);
			}
		}
		for (i = 0; tokens[i]; i++)
		{
			free(tokens[i]);
			tokens[i] = NULL;
		}
		free(tokens);
		tokens = NULL;
	}
	free(line);
	free(shell_name);
	shell_name = NULL;
	line = NULL;
	return (cmd_status);
}

