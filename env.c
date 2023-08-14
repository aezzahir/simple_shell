#include "main.h"

void print_environment() {
    extern char **environ; // The array containing environment variables
    int i = 0;

    // Loop through the array and print each environment variable
    while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }
}
