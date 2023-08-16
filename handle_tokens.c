#include "main.h"
/**
 * get_number_of_tokens - a function that returns the number
 * of tokens in a given command
 * @command: the command line
 * @delim: the delimiter “space” or “:”
 * Return: the number of tokens
*/
int get_number_of_tokens(char *command, const char *delim)
{
int number_of_tokens = 0;
char *a_token;
a_token = strtok(command, delim);
while (a_token != NULL)
{
number_of_tokens++;
a_token = strtok(NULL, delim);
}
number_of_tokens++;
return (number_of_tokens);
}
/**
 * tokenize_input - function that tokenize a command
 * @line_copy: a command copy
 * @delim: the delimiter
 * @number_of_tokens: the number of tokens
 * Return: a pointer to pointer to the tokens’ vector
*/
char **tokenize_input(char *line_copy, const char *delim, int number_of_tokens)
{
char **tokens = malloc(sizeof(char *) * number_of_tokens);
int i;
char *a_token;
if (!tokens)
{
return (NULL);
}
a_token = strtok(line_copy, delim);
for (i = 0; a_token != NULL; i++)
{
tokens[i] = malloc(sizeof(char) * (strlen(a_token) + 1));
if (!tokens[i])
{
memory_allocation_error();
}
_strcpy(tokens[i], a_token);
a_token = strtok(NULL, delim);
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
