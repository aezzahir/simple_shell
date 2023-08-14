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


/* Utilities functions */
int _printf(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);

/* Shell functions */
void prompt(void);
void execmd(char **argv, char *argv_0);
char *get_path(char *command);
void print_env();
int exit_function(char **tokens, const char *argv_0);


#endif /* _MAIN_H */
