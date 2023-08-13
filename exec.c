#include "main.h"

void execmd(char **argv){
    char *line = NULL;

    if (argv){
        /* get the command */
        line = argv[0];

        /* generate the path to this command before passing it to execve */

        /* execute the actual command with execve */
        if (execve(line, argv, NULL) == -1){
            _printf(line);
            _printf(": 1: qwerty: not found");
        }
    }

}