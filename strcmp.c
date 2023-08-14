# include "main.h"
/**
 * _strcmp -  copies a string
 * @s1: the first string
 * @s2: the second string
 * Return: returns the result of comparaison
 */

int _strcmp(char *s1, char *s2)
{
while (*s1 != '\0' && *s2 != '\0')
{
if (*s1 != *s2)
{
return (*s1 - *s2);
}
s1++;
s2++;
}
if (*s1 == '\0' && *s2 == '\0')
{
return (0);
}
return (0);
}
