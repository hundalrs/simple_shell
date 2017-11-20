#ifndef _SHELL
#define _SHELL

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>

/**
 * struct builtin - pointer to chars and function pointer
 * @command: pointer to char
 * @f: function pointer
 */
typedef struct builtin
{
	char *command;
	int (*f)(char **_argv);

} builtin;

int main(void);
void create_instance(void);
int main_shell(void);
char **tokenizer(char **buffer, char *pattern);
void _exec_process(char *_arg, char **_args);
int print_env(char **_argv);
int _strcmp(char *s1, char *s2);
int _exiting(char **_argv);
int _putchar(char c);
int is_arg_ready(char *_argv);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *get_x_args(char **tmp_args, char *prog);
char *getPathArgs(char *prog, char **environ);
char *getKeyValue(char *key, char **environ);
char *_strstr(char *haystack, char *needle);
char *_stralloc(int count, ...);
int _strlen(char *s);
int countToks(char *str, char *delim);
extern char **environ;

#define EXIT_SHELL 3
#define DEFAULT 1
#define BUILTIN 5
#define START_OVER 7

#endif
