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

int main();
void create_instance();
void main_shell();
void tokenizer (char ***_argv, char **buffer);
void _exec_process(char **argv);

#endif
