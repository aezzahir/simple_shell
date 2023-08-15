#include "main.h"

/**
 * print_environment - prints the env variable
 * @env: the global variable to print
 */


void print_environment(char **env)
{
int i = 0;
while (env[i] != NULL)
{
_printf(env[i]);
_printf("\n");
i++;
}
}
