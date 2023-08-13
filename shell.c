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
    size_t linecap = 0;
    ssize_t linelen;
     const char *delim = " \n";
    int number_of_tokens = 0;
    char *a_token;
    int i;

    (void)ac;
    /* copy of argv[0] to use it when printing errors */
    _strcpy(argv_0, argv[0]);


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
        if (line_copy== NULL)
        {
            perror("tsh: memory allocation error");
            return (-1);
        }
        /* copy lineptr to lineptr_copy */
        _strcpy(line_copy, line);

        /********** split the string (lineptr) into an array of words ********/
        /* calculate the total number of tokens */
        a_token = strtok(line, delim);

        while (a_token != NULL){
            number_of_tokens++;
            a_token = strtok(NULL, delim);
        }
        number_of_tokens++;

        /* Allocate space to hold the array of strings */
        argv = malloc(sizeof(char *) * number_of_tokens);

        /* Store each token in the argv array */
        a_token = strtok(line_copy, delim);

        for (i = 0; a_token != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(a_token));
            _strcpy(argv[i], a_token);

            a_token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        /* execute the command */
        execmd(argv, argv_0);
    }
     /* free up allocated memory */ 
    free(line);
    free(line_copy);

    
}
