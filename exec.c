#include "main.h"

/**
 * execmd - Executes a command.
 * @argv: Array of command arguments
 */
/**
 * execmd - Executes a command.
 * @argv: Array of command arguments.
 * Return: -1 on fork error, -100 if command path not found, or 0 on success.
 */
int execmd(char **argv)
{
	char *command = NULL, *full_command = NULL;
	pid_t pid;
	int status;

	if (!argv || !argv[0])
		return (-100);

	command = argv[0];
	full_command = get_path(command);

	if (!full_command)
	{
		perror("Error: Command path not found");
		return (-100);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(full_command, argv, NULL) == -1)
		{
			free(full_command);
			perror("Error: Execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		free(full_command);
		perror("Error: Fork failed");
		return (-1);
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	if (_strcmp(command, "env") == 0)
		print_environment();

	free(full_command);
	return (0);
}

/**
 * exec_multiple_cmds - Executes multiple commands separated by ';'.
 * @line: Input line containing multiple commands
 * @argv_0: Name of the shell program
 * @delim: the delimiter
 */
void exec_multiple_cmds(char *line, const char *delim)
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
		execmd(tokens);
		for (i = 0; tokens[i]; i++)
		{
			free(tokens[i]);
		}
		token = _strtok(NULL, ";");
	}
	free(tokens);
}

