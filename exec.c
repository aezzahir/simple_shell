#include "main.h"

void execmd(char **argv, char *argv_0) 
{
    char *command = NULL, *full_command = NULL;
    pid_t pid, wpid;
    int status;

    if (!argv || !argv[0]) {
        return;
    }
    /* get the command */
    command = argv[0];
    /* generate the path to this command before passing it to execve */
    full_command = get_path(command);
    pid = fork();
    if (pid == 0) {
        if (execve(full_command, argv, NULL) == -1) {
            _printf(argv_0);
            _printf(": No such file or directory\n");
            exit(EXIT_FAILURE);  // Make sure the child process terminates
        }
    } else if (pid < 0) {
        // Forking failed
        perror("tsh");
    } else {
        // This block will be run by the parent
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    if (_strcmp(command, "env") == 0) {
        // Call the function to print the environment variables
        print_environment();
        // Free allocated memory and return
        free(line_copy);
        for (i = 0; tokens[i]; i++)
            free(tokens[i]);
        free(tokens);
        return;
    }
}
