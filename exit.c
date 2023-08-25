#include "main.h"

/**
 * exit_builtin - Implementation of the "exit" built-in command
 * @tokens: Array of tokens from the user input
 * Return: 0 if the shell should exit, -1 on error
 */
int exit_builtin(char **tokens)
{
	int exit_status;

	if (tokens[1] == NULL)
	{
		return (0);
	}
	else if (tokens[2] != NULL)
	{
		_printf("Error: too many arguments\n");
		return (-1);
	}

	exit_status = _atoi(tokens[1]);
	return (exit_status);
}


