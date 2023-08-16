#include "main.h"

/**
 * execmd - Executes a command.
 * @argv: Array of command arguments
 * @argv_0: Name of the shell program
 */

void execmd(char **argv, char *argv_0)
{
char *command = NULL, *full_command = NULL;
pid_t pid;
int status;

if (!argv || !argv[0])
{
return;
}
command = argv[0];
full_command = get_path(command);
if (!full_command)
{
_printf(argv_0);
_printf(": No such file or directory\n");
return;
}
pid = fork();
if (pid == 0)
{
if (execve(full_command, argv, NULL) == -1)
{
_printf(argv_0);
_printf(": Error executing command\n");
exit(EXIT_FAILURE);
}
}
else if (pid < 0)
{
perror("tsh");
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
if (_strcmp(command, "env") == 0)
{
print_environment();
}
}
