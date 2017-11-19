#include "holberton.h"

void create_instance()
{
        pid_t pid;
	int status;
	size_t stat;

        pid = fork();

	if (pid == -1)
	{
		perror("Cannot fork process");
		exit (EXIT_FAILURE);
	}
        if (pid == 0)
	{
		stat = main_shell();
		switch (stat) {
		case 3:
			exit(0);
			break;
		default:
			exit(1);
		}
	}
	wait (&status);
	stat = WEXITSTATUS (status);
	if (stat)
		create_instance();
	else
		return;
}

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
		//set stat = NEED_PATH or USED_PATH
		stat = is_arg_ready(_argv[0]) ? NEED_PATH : USED_PATH;
	}

	if (stat == NEED_PATH)
	{
		path = getPathArgs(_argv[0], environ);
		stat = USED_PATH;
	}
	if (stat == USED_PATH)
	{
		//change this
		_exec_process(path ? path : _argv[0], _argv);
		wait(NULL);
	}
	if (path != NULL)
		free(path);
	if (buffer != NULL)
		free(buffer);
	if (_argv != NULL)
		free(_argv);

	return (stat);
}

int is_arg_ready (char *_argv)
{
	if (access(_argv, X_OK) == -1)
		return (4);
	else
		return (2);

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
