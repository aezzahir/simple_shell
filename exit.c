#include "main.h"


/**
 * exit_builtin - Implementation of the "exit" built-in command
 * @tokens: Array of tokens from the user input
 * Return: 0 if the shell should exit, -1 on error
 */
void exit_builtin(char **tokens)
{
	if (tokens[1])
	{
		int status = atoi(tokens[1]);
		exit(status);
	}
	exit(0);
}

