#include "main.h"


// ... (Other function declarations, such as _strcpy and execmd)

/**
 * exit_builtin - Implementation of the "exit" built-in command
 * @tokens: Array of tokens from the user input
 * @argv_0: Name of the shell program
 * Return: 0 if the shell should exit, -1 on error
 */
int exit_builtin(char **tokens, const char *argv_0) {
    // Check if the "exit" command was used with the correct number of arguments
    if (tokens[1] == NULL) {
        // No argument, exit with status 0
        return 0;
    } else if (tokens[2] != NULL) {
        // Too many arguments
        perror("too many arguments\n");
        return -1;
    }

    // Convert the status argument to an integer
    int exit_status = _atoi(tokens[1]);

    // Free allocated memory (tokens, line, line_copy, etc.) if necessary

    // Return the exit status
    return exit_status;
}

