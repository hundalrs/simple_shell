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

typedef struct builtin
{
	char *command;
	void (*f)(char **_argv);

} builtin;

int main(int ac, char *av[], char *env[]);
void create_instance();
void main_shell();
char **tokenizer (char **buffer);
void _exec_process(char **argv);
void print_env(char**_argv);
int _strcmp(char *s1, char *s2);
void _exiting(char **_argv);
int _putchar(char c);
extern char **environ;

#endif
