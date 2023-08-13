#include "main.h"

void execmd(char **argv, char *argv_0) 
{
    char *command = NULL;

    if (argv && argv[0]) {
        /* Get the command */
        command = argv[0];

        /* Execute the actual command with execve */
        if (execve(command, argv, NULL) == -1) {
            // Print an error message if execve fails
            _printf(argv_0);
            _printf(": No such file or directory\n");
        }
    }
}
