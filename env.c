#include "main.h"

void print_env() {
    extern char **environnement; // The array containing environment variables
    int i = 0;

    // Loop through the array and print each environment variable
    while (environnement[i] != NULL) {
        _printf(environnement[i]);
        i++;
    }
}
