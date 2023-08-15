#include "main.h"

/**
 * print_environment - prints the env variable
 * @environ: the global variable to print
 */


void print_environment(char **env)
{
extern char **environ;
int i = 0;
while (environ[i] != NULL)
{
_printf(environ[i]);
_printf("\n");
i++;
}
}
