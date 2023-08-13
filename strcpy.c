#include "main.h"

/**
 * _strcpy - copies the string pointed to by src to the one pointed to by dest
 * @dest: the destination
 * @src: the source
 * Return: returns the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
int i;
int leng = 0;
while (src[leng] != '\0')
{
leng++;
}
for (i = 0; i <= leng; i++)
{
dest[i] = src[i];
}
return (dest);
}
