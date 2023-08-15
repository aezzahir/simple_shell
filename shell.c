#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - main function
 * @ac: Arguments Number
 * @argv: Arguments Vector
 * Return: 0 if success
*/

int main(int ac, char **argv)
{

    char *line = NULL, *line_copy = NULL, argv_0[100];
    char **tokens = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    const char *delim = " \n";
    int number_of_tokens = 0;
    char *a_token;
    int i;

    (void)ac;
    /* copy of argv[0] to use it when printing errors */
    _strcpy(argv_0, argv[0]);


    /* ... Your other code ... */

    while (1)
    {
        prompt();

        linelen = getline(&line, &linecap, stdin);
        if (linelen == -1)
        {
            _printf("\n");
            return (-1);
        }

        line_copy = malloc(sizeof(char) * linelen);
        if (!line_copy)
        {
            perror("tsh: memory allocation error");
            return (-1);
        }
        _strcpy(line_copy, line);

        /* split the string (line) into an array of words */
        number_of_tokens = 0;
        a_token = strtok(line, delim);
        while (a_token != NULL)
        {
            number_of_tokens++;
            a_token = strtok(NULL, delim);
        }
        number_of_tokens++;

        tokens = malloc(sizeof(char *) * number_of_tokens);
        if (!tokens)
        {
            perror("tsh: memory allocation error");
            free(line_copy);
            return (-1);
        }

        a_token = strtok(line_copy, delim);
        for (i = 0; a_token != NULL; i++)
        {
            tokens[i] = malloc(sizeof(char) * (strlen(a_token) + 1)); // +1 for '\0'
            _strcpy(tokens[i], a_token);
            a_token = strtok(NULL, delim);
        }
        tokens[i] = NULL;

        /* Check if the first command is "exit" */
        if (tokens[0] && strcmp(tokens[0], "exit") == 0) {
            int exit_status = exit_builtin(tokens);
            // Free allocated memory (tokens, line, line_copy, etc.) if necessary
            return exit_status;
        }

        execmd(tokens, argv_0);

        /* Free the tokens and line_copy */
        for (i = 0; tokens[i]; i++)
            free(tokens[i]);
    }
    free(tokens);
    free(line_copy);
    free(line);
}
