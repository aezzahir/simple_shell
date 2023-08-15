#include "main.h"

void free_tokens(char **tokens) {
    int i;
    for (i = 0; tokens[i]; i++)
        free(tokens[i]);
    free(tokens);
}