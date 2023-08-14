#include "main.h"
/**
 * _atoi - converts a string to an integer.
 * @s: string to be converted
 * Return: converted integer
 */
int _atoi(char *s)
{
int index, negative, number, prev_index;

index = 0;
negative = 0;
number = 0;
prev_index = 0;

while (*(s + index) != '\0')
{
if (*(s + index) == '-' && prev_index == 0)
{
negative++;
}
if (*(s + index) >= 48 && *(s + index) <= 57)
{
if (negative % 2 == 0)
{
number = number * 10 + (*(s + index) -48);
}
else
{
number = number * 10 - (*(s + index) -48);
}
prev_index = index;
}
if (prev_index != 0 && prev_index != index)
{
break;
}
index++;
}

return (number);
}
