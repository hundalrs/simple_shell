#include "holberton.h"

int main_shell()
{
	int i = 0;
        char *buffer = NULL, *path = NULL;
        size_t bufsize = 0;
	char **_argv = NULL;
	ssize_t exit_check;
	unsigned int stat = DEFAULT;

	builtin funcs[] = {
		{"env", print_env},
//		{"exit", _exiting},
		{NULL, NULL}
		};

        write(STDOUT_FILENO, "#cisfun$ ", 9);

	exit_check = getline (&buffer, &bufsize, stdin);
	if (exit_check == -1)
		stat = EXIT_SHELL;
	if (exit_check == 1)
		stat = START_OVER;

	if (stat == DEFAULT)
	{
		_argv = tokenizer(&buffer, " \n\t\r");

		while (funcs[i].command && access(_argv[0], X_OK) == -1)
		{
			if (_strcmp (_argv[0], funcs[i].command) == 0)
			{
				funcs[i].f(_argv);
				stat = BUILTIN;
				break;
			}
			i++;
		}
	}

	if (stat == DEFAULT)
	{
		if (access(_argv[0], X_OK) == -1)
			path = getPathArgs(_argv[0], environ);
		_exec_process(path ? path : _argv[0], _argv);
	}

	if (stat == EXIT_SHELL)
		write (STDOUT_FILENO, "\n", 1);

	free(path);
	free(buffer);
	free(_argv);

	return (stat);
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
