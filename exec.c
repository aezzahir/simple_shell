#include "main.h"

/**
 * free_full_path - free full path
 * @full_command: command
 * Return: 0
 */

int free_full_path(char *full_command)
{
	free(full_command);
	full_command = NULL;
	return (0);

}

/**
 * print_error - Print the error message to stderr.
 * @command: The failing command name.
 * @full_command: The full path to the failing command.
 * Return: Nothing.
 */
void print_error(char *command, char *full_command)
{
	(void)full_command;
	if (command[0] == '/')
	{
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, command, _strlen(command));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
	}
	else
	{
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, command, _strlen(command));
		write(STDERR_FILENO, ": not found\n", 12);
	}
}

/**
 * execmd - Executes a command.
 * @argv: Array of command arguments.
 * @shell_name: shell_name
 * Return: -1 on fork error, -100 if command path not found, or 0 on success.
 */

int execmd(char **argv, char *shell_name)
{
	char *command = NULL, *full_command = NULL;
	pid_t pid;
	int status;

	if (!argv || !argv[0])
		return (0);
	command = argv[0];
	full_command = get_path(command);
	if (!full_command)
	{
		write(STDERR_FILENO, shell_name, _strlen(shell_name));
		print_error(command, full_command);
		free_full_path(full_command);
	}
	if (_strcmp(command, "env") == 0)
	{
		print_environment();
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(full_command, argv, NULL) == -1)
			return (0);
	}
	else if (pid < 0)
		free_full_path(full_command);
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		free(full_command);
		return (WEXITSTATUS(status));
	}
	return (0);
}


/**
 * exec_multiple_cmds - Executes multiple commands separated by ';'.
 * @line: Input line containing multiple commands
 * @shell_name: shell_name
 * @delim: the delimiter
 */
void exec_multiple_cmds(char *line, const char *delim, char *shell_name)
{
	char *token;
	char **tokens;
	int i;
	const char *d = ";";

	token = *get_tokens(line, d);
	while (token != NULL)
	{
		tokens = NULL;
		tokens = get_tokens(token, delim);
		execmd(tokens, shell_name);
		for (i = 0; tokens[i]; i++)
		{
			free(tokens[i]);
		}
		token = _strtok(NULL, ";");
	}
	free(tokens);
}

