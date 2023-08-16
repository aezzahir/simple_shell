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

/**
 * exec_multiple_cmds - Executes multiple commands separated by ';'.
 * @line: Input line containing multiple commands
 * @argv_0: Name of the shell program
 * @delim: the delimiter
 */
void exec_multiple_cmds(char *line, char *argv_0, const char *delim)
{
int number_of_tokens, number_of_commands;
char *token;
char **tokens;
int i;
const char *d = ";";
char *line_copy = malloc(sizeof(char) * (strlen(line) + 1));
if (!line_copy)
{
memory_allocation_error();
return;
}
_strcpy(line_copy, line);
number_of_commands = get_number_of_tokens(line, d);
token = *tokenize_input(line, d, number_of_commands);
while (token != NULL)
{
tokens = NULL;
number_of_tokens = get_number_of_tokens(token, delim);
tokens = tokenize_input(token, delim, number_of_tokens);
execmd(tokens, argv_0);
for (i = 0; tokens[i]; i++)
{
free(tokens[i]);
}
token = strtok(NULL, ";");
}
free(line_copy);
}

