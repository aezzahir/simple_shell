#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to return the length of
 * Return: returns the length of the string
 */

int _strlen(char *s)
{
int compt = 0;
int i = 0;
while (s[i] != '\0')
{
compt++;
i++;
}
return (compt);
}
