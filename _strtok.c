#include "main.h"

/**
 * _strtok - tokenizes a string based on a delimiter
 * @str: input string
 * @delim: delimiter string
 *
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *last_token = NULL;
	char *token_start;
	int i;

	if (str == NULL)
		str = last_token;

	if (str == NULL)
		return (NULL);

	/* Skip any leading delimiters */
	for (; *str; str++)
	{
		for (i = 0; delim[i] && *str != delim[i]; i++)
			;
		if (!delim[i]) /* Not a delimiter */
			break;
	}

	/* Check if we reached the end of the string */
	if (*str == '\0')
	{
		last_token = NULL;
		return (NULL);
	}

	token_start = str;

	/* Find the end of the token */
	for (; *str; str++)
	{
		for (i = 0; delim[i]; i++)
		{
			if (*str == delim[i])
			{
				*str = '\0';
				last_token = str + 1;
				return (token_start);
			}
		}
	}

	/* Return the final token */
	last_token = NULL;
	return (token_start);
}
