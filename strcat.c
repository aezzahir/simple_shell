#include "main.h"

/**
 * _strcat-concatenates two strings
 * @dest: the destination
 * @src: the source
 * Return: returns dest
 */

char *_strcat(char *dest, char *src)
{
int i;
int leng1 = 0;
int leng2 = 0;
while (dest[leng1] != '\0')
{
leng1++;
}
while (src[leng2] != '\0')
{
leng2++;
}
dest[leng1 - 1] = ' ';
for (i = 0; i < leng2; i++)
{
dest[leng1 + i] = src[i];
}
return (dest);
}