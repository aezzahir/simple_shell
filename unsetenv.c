#include "main.h"

/**
 * _unsetenv - Remove an environment variable
 * @variable: the variable to remove
 * Return: returns 0 (success)
 */
int _unsetenv(char *variable)
{
int i;
for (i = 0; i < num_vars; i++)
{
if (_strcmp(env_vars[i], variable) == 0)
{
for (int j = i; j < num_vars - 1; j++)
{
_strcpy(env_vars[j], env_vars[j + 1]);
_strcpy(env_vals[j], env_vals[j + 1]);
}
num_vars--;
return (0);
}
}
perror("Variable not found");
return (-1);
}


