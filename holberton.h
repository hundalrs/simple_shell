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

typedef struct builtin
{
	char *command;
	void (*f)(char **_argv);

} builtin;

int main();
void create_instance();
int main_shell();
char **tokenizer (char **buffer, char *pattern);
void _exec_process(char *_arg, char **_args);
void print_env(char**_argv);
int _strcmp(char *s1, char *s2);
void _exiting(char **_argv);
int _putchar(char c);
int is_arg_ready(char *_argv);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *get_x_args(char **tmp_args, char *prog);
char *getPathArgs(char *prog, char **environ);
char *getKeyValue(char *key, char **environ);
char *_strstr(char *haystack, char *needle);
char *allocate_strings (int count, ...);
int _strlen(char *s);
int countToks(char *str, char *delim);
extern char **environ;

#define EXIT_SHELL 3
#define DEFAULT 1
#define USED_PATH 2
#define NEED_PATH 4
#define BUILTIN 5

#endif
