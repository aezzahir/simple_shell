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

    char *line = NULL, *line_copy = NULL;
    size_t linecap = 0;
    ssize_t linelen;

    (void)ac;

    while (1)
    {
        prompt();

        linelen =  getline(&line, &linecap, stdin);

        /* check if the getline function failed or reached EOF or user use CTRL + D */ 
        if (linelen == -1)
        {
            _printf("\n");
            return (-1);
        }

        /* allocate space for a copy of the lineptr */
        line_copy = malloc(sizeof(char) * linelen);
        if (line_copy== NULL){
            perror("tsh: memory allocation error");
            return (-1);
        }
        /* copy lineptr to lineptr_copy */
        strcpy(line_copy, line);

        /* execute the command */
        argv = malloc(sizeof(char *) * 100);
        argv[0] = line;
        execmd(argv);
    }
     /* free up allocated memory */ 
    free(line);
    free(line_copy);

    
}
