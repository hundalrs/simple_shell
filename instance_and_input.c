#include "holberton.h"

/**
 * main_shell - calls functions and prints prompt
 * Return: returns status
 */
int main_shell(void)
{
	int i = 0, exit_check;
	char *buffer = NULL, *path = NULL;
	size_t bufsize = 0;
	char **_argv = NULL;
	unsigned int stat = DEFAULT;
	builtin funcs[] = {
		{"env", print_env},
		{"exit", _exiting},
		{NULL, NULL}
		};

	write(STDOUT_FILENO, "#cisfun$ ", 9);
	exit_check = getline(&buffer, &bufsize, stdin);
	if (exit_check == -1)
		stat = EXIT_SHELL;
	if (exit_check == 1)
		stat = START_OVER;
	if (stat == DEFAULT)
	{
		_argv = tokenizer(&buffer, "\n\t\r ");
		while ((funcs[i].command && access(_argv[0], X_OK) == -1))
		{
			if ((_strcmp(_argv[0], funcs[i].command) == 0) &&
			    (_strlen(_argv[0]) == _strlen(funcs[i].command)))
			{
				stat = funcs[i].f(_argv);
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
	free(path); free(buffer); free(_argv);
	return (stat);
}

/**
 * _exiting - exit shell
 * Return: returns status(3) to exit shell
 * @_argv: array of tokenized strings
 */
int _exiting(char **_argv)
{
	(void) _argv;
	return (3);
}

/**
 * print_env - prints environment
 * Return: returns 1 which is default
 * @_argv: array of tokenized strings
 */
int print_env(char **_argv)
{
	(void) _argv;
	int i = 0, j;

	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
	return (1);
}
