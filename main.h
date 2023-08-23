#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char **splitter(char *str, char *delim);
char *_which(char* file);
char *_getenv(char *name);
void print_dirs();
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int print_environ();
int _strlen(char *s);
char *_strcpy(char *copy, char *original);
int _strcmp(char *s1, char *s2);
char *_strcat(char *string, char *addon);
void _printf(char *str);
void _perror(char *message);

#endif
