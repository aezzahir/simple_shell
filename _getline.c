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
    int fd = fileno(stream);
    ssize_t bytes_read;

    if (!lineptr || !n || fd == -1)
        return (-1);

    if (!*lineptr)
    {
        *lineptr = malloc(initial_size);
        if (!*lineptr)
            return (-1);
        *n = initial_size;
    }
    curr_size = *n;
    ptr = *lineptr;
    idx = 0;

    bytes_read = read(fd, &c, 1);  // Using read instead of getc.

    while (bytes_read > 0 && c != '\n')
    {
        if (idx >= curr_size - 1)
        {
            curr_size *= 2;
            new_ptr = malloc(curr_size);  // Allocate new buffer.
            if (!new_ptr)
                return (-1);

            _memcpy(new_ptr, ptr, idx);  // Use our own memcpy function.
            free(ptr);  // Free old buffer.

            *n = curr_size;
            ptr = new_ptr;
            *lineptr = new_ptr;
        }
        ptr[idx++] = c;
        bytes_read = read(fd, &c, 1);  // Using read in loop.
    }

    if (bytes_read > 0 && c == '\n')
    {
        ptr[idx++] = c;
    }
    ptr[idx] = '\0';

    if (bytes_read <= 0 && idx == 0)
        return (-1);  // Indicate EOF or error.

    return (idx);
}
