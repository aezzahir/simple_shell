#ifndef _MAIN_H
#define _MAIN_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

/* External variables */
extern char **environ;

/* Utilities functions */
int _printf(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strchr(char *s, char c);

/* Shell functions */
void prompt(void);
int execmd(char **argv, char *shell_name);
char *get_path(char *command);
void print_environment(void);
int exit_builtin(char **tokens);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void exec_multiple_cmds(char *line, const char *delim, char *shell_name);
char *_strtok(char *str, const char *delim);
/* Split command utility functions */
char **get_tokens(char *line_copy, const char *delim);
int memory_allocation_error(void);
void print_error(char *command, char *full_command);

#endif /* _MAIN_H */
