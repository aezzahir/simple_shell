#include "main.h"

/**
 * _printf -  printf function
 * @str: string to be printed
 * Return: number of char in the string
*/

int _printf(const char *str)
{
int length = 0;
while (str[length] != '\0')
{
length++;
}
return (write(STDOUT_FILENO, str, length));
}
