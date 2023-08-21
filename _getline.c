#include "main.h"

/**
 * _realloc_and_copy - Reallocates memory and copies content.
 * @old_ptr: Pointer to old memory block.
 * @old_size: Size of the old memory block.
 * @new_size: Size for the new memory block.
 * Return: Pointer to the new memory block.
 */
static char *_realloc_and_copy(char *old_ptr, size_t old_size, size_t new_size)
{
    char *new_ptr;

    new_ptr = malloc(new_size);
    if (!new_ptr)
        return (NULL);
    _memcpy(new_ptr, old_ptr, old_size);
    free(old_ptr);
    return (new_ptr);
}

/**
 * _read_from_fd - Reads a character from a file descriptor.
 * @fd: File descriptor.
 * @c: Pointer to char where the read character will be stored.
 * Return: Number of bytes read.
 */
static ssize_t _read_from_fd(int fd, char *c)
{
    return (read(fd, c, 1));
}

/**
 * _getline - Reads a line from a stream.
 * @lineptr: Pointer to the buffer that will hold the read line.
 * @n: Pointer to the size of the buffer.
 * @stream: Stream to read from.
 * Return: Number of characters read.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    const size_t initial_size = 128;
    size_t idx = 0, curr_size;
    char c;
    int fd;
    ssize_t bytes_read;

    if (!lineptr || !n)
        return (-1);
    fd = fileno(stream);
    if (fd == -1)
        return (-1);
    if (!*lineptr)
    {
        *lineptr = malloc(initial_size);
        if (!*lineptr)
            return (-1);
        *n = initial_size;
    }
    curr_size = *n;
    bytes_read = _read_from_fd(fd, &c);
    while (bytes_read > 0 && c != '\n')
    {
        if (idx >= curr_size - 1)
        {
            curr_size *= 2;
            *lineptr = _realloc_and_copy(*lineptr, idx, curr_size);
            if (!*lineptr)
                return (-1);
            *n = curr_size;
        }
        (*lineptr)[idx++] = c;
        bytes_read = _read_from_fd(fd, &c);
    }
    if (bytes_read > 0 && c == '\n')
        (*lineptr)[idx++] = c;
    (*lineptr)[idx] = '\0';
    if (bytes_read <= 0 && idx == 0)
        return (-1);
    return (idx);
}
