#include "main.h"

/**
 * _memcpy - memcpy function
 * @dest: destination file
 * @src: file
 * @n: size
 * Return: void
*/

void *_memcpy(void *dest, const void *src, size_t n)
{
char *d = (char *) dest;
const char *s = (const char *) src;

while (n--)
{
*d++ = *s++;
}
return (dest);
}
