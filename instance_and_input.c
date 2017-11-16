#include "holberton.h"

void create_instance()
{
        pid_t pid;

        pid = fork();
        if (pid == 0)
	{
		main_shell();
	}
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
	int i = 0;
        char *buffer = NULL;
        size_t bufsize = 0;
	char **_argv;

	builtin funcs[] = {
		{"env", print_env},
		{"exit", _exiting},
		{NULL, NULL}
		};

        write(STDOUT_FILENO, "#cisfun$ ", 9);

        getline (&buffer, &bufsize, stdin);

        _argv = tokenizer(&buffer);

	while (funcs[i].command && access(_argv[0], X_OK) == -1)
	{
		if (_strcmp (_argv[0], funcs[i].command) == 0)
		{
			funcs[i].f(_argv);
			break;
		}
		i++;
	}
	if (_argv[0] != NULL)
		_exec_process(_argv);

	wait(NULL);

        free(buffer);
        free(_argv);
}

void _exiting(char**_argv)
{
	(void) _argv;
	_exit(1);
}

void print_env(char **_argv)
{
	(void) _argv;
	int i = 0, j = 0;

	while (environ[i])
	{
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}
		i++;
		_putchar('\n');
	}
}
