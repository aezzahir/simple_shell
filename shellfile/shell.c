#include "main.h"

#define BUFFER_SIZE 1024

/**
 * setup_shell_name - Set up the shell name.
 * @arg: Argument for shell name.
 * Return: shell name.
 */
char *setup_shell_name(char *arg)
{
	char *shell_name = malloc(_strlen(arg) + 1);

	if (!shell_name)
		exit(EXIT_FAILURE);
	_strcpy(shell_name, arg);

	return (shell_name);
}

/**
 * process_command - Process the command input.
 * @line: The input line.
 * @delim: Delimiter for tokenization.
 * @shell_name: Name of the shell.
 */
void process_command(char *line, const char *delim, char *shell_name)
{
	char **tokens = NULL;
	int i;

	if (_strchr(line, ';'))
	{
		exec_multiple_cmds(line, delim, shell_name);
		return;
	}
	tokens = get_tokens(line, delim);
	if (tokens[0])
	{
		if (!_strcmp(tokens[0], "exit"))
		{
			exit_builtin(tokens);
			return;
		}
		execmd(tokens, shell_name);
	}
	for (i = 0; tokens[i]; i++)
	{
		free(tokens[i]);
		tokens[i] = NULL;
	}
	free(tokens);
}

/**
 * command_loop - The main loop to get command input.
 * @shell_name: The name of the shell.
 */
void command_loop(char *shell_name)
{
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;
	const char *delim = " \n";

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
		process_command(line, delim, shell_name);
	}
	free(line);
}

/**
 * main - Entry point of the program.
 * @ac: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: 0 on success, or other status on failure.
 */
int main(int ac, char **argv)
{
	char *shell_name = NULL;
	int cmd_status = 0;

	(void)ac;
	shell_name = setup_shell_name(argv[0]);
	command_loop(shell_name);
	free(shell_name);
	return (cmd_status);
}

