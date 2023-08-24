#include "main.h"

/**
 * get_tokens - Tokenizes a command.
 * @line_copy: A copy of the command line.
 * @delim: The delimiter for tokenization.
 *
 * Return: A pointer to the array of tokens.
 */
char **get_tokens(char *line_copy, const char *delim)
{
	char **tokens;
	char *a_token, *temp_copy;
	int number_of_tokens = 0, i, j;

	temp_copy = strdup(line_copy);
	if (!temp_copy)
		return (NULL);

	a_token = _strtok(temp_copy, delim);
	while (a_token)
	{
		number_of_tokens++;
		a_token = _strtok(NULL, delim);
	}
	free(temp_copy);

	tokens = malloc(sizeof(char *) * (number_of_tokens + 1));
	if (!tokens)
		return (NULL);

	a_token = _strtok(line_copy, delim);
	for (i = 0; a_token && i < number_of_tokens; i++)
	{
		tokens[i] = strdup(a_token);
		if (!tokens[i])
		{
			for (j = 0; j < i; j++)
				free(tokens[j]);
			free(tokens);
			return (NULL);
		}
		a_token = _strtok(NULL, delim);
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * memory_allocation_error - return error
 * Return: -1
 */

int memory_allocation_error(void)
{
	perror("tsh: memory allocation error");
	return (-1);
}
