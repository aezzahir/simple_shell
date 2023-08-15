#include "main.h"

/**
 * _getline - get line function
 * @lineptr: command
 * @n: size
 * @stream: file stream
 * Return: number of char 
*/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream) 
{
const size_t initial_size = 128;
size_t curr_size;
size_t idx;
char *ptr, *new_ptr;
char c;

if (!lineptr || !n || !stream)
{
return (-1);
}
if (!*lineptr) 
{
*lineptr = malloc(initial_size);
if (!*lineptr) 
{
return (-1);
}
*n = initial_size;
}
curr_size = *n;
ptr = *lineptr;
idx = 0;
c = getc(stream);
while (c != EOF && c != '\n')
{
if (idx >= curr_size - 1) 
{
curr_size *= 2;
new_ptr = realloc(ptr, curr_size);
if (!new_ptr) 
{
return (-1);
}
*n = curr_size;
ptr = new_ptr;
}
ptr[idx++] = c;
c = getc(stream);
}
if (c == '\n') 
{
ptr[idx++] = c;
}
ptr[idx] = '\0';
return (idx);
}
