#include "holberton.h"

void create_instance()
{
        pid_t pid;

        pid = fork();
        if (pid == 0)
                main_shell();
        else if (pid == -1)
                perror("Cannot fork process");
        else
        {
                wait(NULL);
                create_instance();
        }
}

void main_shell()
{
        char *buffer = NULL;
        size_t bufsize = 0;
        char **_argv;

        write(STDOUT_FILENO, "#cisfun$ ", 9);

        getline (&buffer, &bufsize, stdin);

        tokenizer(&_argv, &buffer);

        _exec_process(_argv);
        wait(NULL);

        free(buffer);
        free(_argv);
}
