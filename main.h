#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


void prompt();
int _printf(const char *str);
void execmd(char **argv);
char *_strcpy(char *dest, char *src);

#endif /* _MAIN_H */
