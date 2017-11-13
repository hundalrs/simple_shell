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

int main(int ac, char *av[], char *env[]);
void create_instance();
void main_shell();
char **tokenizer (char **buffer);
void _exec_process(char **argv);

#endif
