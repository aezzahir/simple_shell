#include "main.h"


/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @variable: the variable to add or to modify
 * @value: the value of the variable to add or to modify
 * Return: returns 0 (success)
 */
int _setenv(char *variable, char *value)
{
int i;
if (num_vars >= MAX_ENV_VARS)
{
perror("Error: Too many environment variables\n");
return (-1);
}

for (i = 0; i < num_vars; i++)
{
if (_strcmp(env_vars[i], variable) == 0)
{
_strcpy(env_vals[i], value);
return (0);
}
}

if (_strlen(variable) >= MAX_VAR_LENGTH || _strlen(value) >= MAX_VALUE_LENGTH)
{
perror("Error: Variable or value is too long\n");
return (-1);
}
_strcpy(env_vars[num_vars], variable);
_strcpy(env_vals[num_vars], value);
num_vars++;
return (0);
}


