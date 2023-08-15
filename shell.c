#include "main.h"
#define BUFFER_SIZE 1024
void free_tokens(char **tokens) {
    int i;
    for (i = 0; tokens[i]; i++)
        free(tokens[i]);
    free(tokens);
}
char **split_line(char *line, const char *delim, int *number_of_tokens) {
    char **tokens = NULL;
    char *a_token;
    int i;
    *number_of_tokens = 0;
    a_token = strtok(line, delim);
    while (a_token != NULL) {
        (*number_of_tokens)++;
        a_token = strtok(NULL, delim);
    }
    (*number_of_tokens)++;
    tokens = malloc(sizeof(char *) * (*number_of_tokens));
    if (!tokens) {
        perror("tsh: memory allocation error");
        return NULL;
    }
    a_token = strtok(line, delim);
    for (i = 0; a_token != NULL; i++) {
        tokens[i] = malloc(sizeof(char) * (strlen(a_token) + 1)); // +1 for '\0'
        _strcpy(tokens[i], a_token);
        a_token = strtok(NULL, delim);
    }
    tokens[i] = NULL;
    return tokens;
}
int main(int ac, char **argv) {
    char *line = NULL, *line_copy = NULL, argv_0[100];
    char **tokens = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    const char *delim = " \n";
    int number_of_tokens = 0;
    (void)ac;
    _strcpy(argv_0, argv[0]);
    /* ... Your other code ... */
    while (1) {
        prompt();
        linelen = getline(&line, &linecap, stdin);
        if (linelen == -1) {
            _printf("\n");
            return (-1);
        }
        line_copy = malloc(sizeof(char) * linelen);
        if (!line_copy) {
            perror("tsh: memory allocation error");
            return (-1);
        }
        _strcpy(line_copy, line);
        tokens = split_line(line, delim, &number_of_tokens);
        if (!tokens) {
            free(line_copy);
            return -1;
        }
        if (tokens[0] && strcmp(tokens[0], "exit") == 0) {
            int exit_status = exit_builtin(tokens);
            free_tokens(tokens);
            free(line_copy);
            free(line);
            return exit_status;
        }
        execmd(tokens, argv_0);
        free_tokens(tokens);
    }
    free(line_copy);
    free(line);
}