#include "main.h"

#define BUFFER_SIZE 1024
int is_interactive_mode;
/**
 * main - main function
 * @ac: Arguments Number
 * @argv: Arguments Vector
 * Return: 0 if success
*/

int main(int ac, char **argv)
{
    char *line = NULL, argv_0[100];
    size_t linecap = 0;
    ssize_t linelen;
    const char *delim = " \n";

    (void)ac;
    is_interactive_mode = isatty(STDIN_FILENO);
    _strcpy(argv_0, argv[0]);

    if (is_interactive_mode)
    {
        // Interactive mode: continuously read and process commands
        while (1)
        {
            prompt();
            linelen = _getline(&line, &linecap, stdin);

            if (linelen == -1)  // handle Ctrl-D
            {
                _printf("\n");
                free(line);
                exit(0);
            }

            process_line(line, argv_0, delim);
        }
    }
    else
    {
        // Non-interactive mode: just process the piped command
        linelen = _getline(&line, &linecap, stdin);
        if (linelen > 0)
        {
            process_line(line, argv_0, delim);
        }

        free(line);
    }

    return (0);
}

void process_line(char *line, char *argv_0, const char *delim)
{
    char *line_copy;
    char **tokens;
    int number_of_tokens;

    if (strchr(line, ';') != NULL)
        exec_multiple_cmds(line, argv_0, delim);

    line_copy = malloc(sizeof(char) * strlen(line) + 1);
    if (!line_copy)
        memory_allocation_error();

    _strcpy(line_copy, line);
    number_of_tokens = get_number_of_tokens(line, delim);
    tokens = tokenize_input(line_copy, delim, number_of_tokens);

    if (tokens[0] && strcmp(tokens[0], "exit") == 0)
    {
        free(line_copy);
        free_tokens(tokens);
        exit(0);
    }

    execmd(tokens, argv_0);
    free(line_copy);
    free_tokens(tokens);
}

void free_tokens(char **tokens)
{
    int i;
    for (i = 0; tokens[i]; i++)
        free(tokens[i]);
    free(tokens);
}
