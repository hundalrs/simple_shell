#include "holberton.h"

/**
 * tokenizer - tokenizes arguments
 * Return: arguments
 * @buf: buffer to tokenizer
 * @pattern: delimiters for tokenization
 */
char **tokenizer(char **buf, char *pattern)
{
	int i = 1;
	char *tok;
	char **args;
	int Tokcount;

	Tokcount = countToks(*buf, pattern);

	tok = strtok(*buf, pattern);
	if (tok == NULL)
	{
		perror("no command passed: ");
		exit(EXIT_FAILURE);
	}
	args = malloc(sizeof(char *) * (Tokcount + 1));
	if (args == NULL)
	{
		perror("Error in Allocation");
		exit(EXIT_FAILURE);
	}
	args[0] = tok;

	while (tok != NULL)
	{
		tok = strtok(NULL, pattern);
		if (tok != NULL)
			args[i] = tok, i++;
	}
	args[i] = NULL;
	return (args);
}

/**
 * countToks - count number of tokens
 * Return: value of number of tokens
 * @str: string
 * @delim: delimiter
 */
int countToks(char *str, char *delim)
{
	int i = 0, j = 0;
	int count = 0;

	while (delim[i] != '\0')
	{
		while (str[j] != '\0')
		{
			if (delim[i] == str[j] && str[j + 1] != delim[i])
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

/**
 * _exec_process - execute command and create child process
 * @_arg: arg
 * @_args: array of args
 */
void _exec_process(char *_arg, char **_args)
{

	pid_t pid;

	pid = fork();

	if (pid == -1)
		perror("Could not fork");
	if (pid == 0)
	{
		if (execve(_arg, _args, NULL) == -1)
		{
			perror("error in execute command");
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
