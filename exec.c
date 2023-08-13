#include "main.h"

void execmd(char **argv, char *argv_0) 
{
    pid_t pid, wpid;
    int status;

    if (!argv || !argv[0]) {
        return;
    }

    pid = fork();
    if (pid == 0) {
        // This block will be run by the child process
        if (execve(argv[0], argv, NULL) == -1) {
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
}
