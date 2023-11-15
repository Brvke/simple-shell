#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \n\t"

char *read_line(void);
char **tokenizer(char *line);
int _execute(char **cmd, char **argv, int idx);
char *_getpath(char *cmd);
char *_getenv(char *var);
extern char **environ;

int _strlen(char *s);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

void freearray(char **array);
void p_error(char *dis, char *cmd, int idx);
void rev_str(char *str, int len);
int is_posnum(char *str);
int _atoi(char *str);
char *_itoa(int value);

void print_env(char **cmd, int *stat);
int _builtin(char *cmd);
void exit_shell(char **cmd, char **argv, int *stat, int idx);
void hbuiltin(char **cmd, char **argv, int stat, int idx);

#endif
