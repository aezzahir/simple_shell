#include "main.h"


int _printf(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return write(STDOUT_FILENO, str, length);
}
