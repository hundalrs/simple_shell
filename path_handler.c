#include "holberton.h"

/**
 * getPathArgs - main function that calls other funcs for PATH
 * Return: returns PATH
 * @prog: program
 * @environ: environment
 */
char *getPathArgs(char *prog, char **environ)
{
	char *tmp;
	char *tmp_env;
	char **tmp_args;

	tmp = getKeyValue("PATH", environ);
	tmp_env = _stralloc(1, tmp);
	tmp_args = tokenizer(&tmp_env, ":");
	tmp = get_x_args(tmp_args, prog);

	free(tmp_args);
	free(tmp_env);
	return (tmp);
}

/**
 * getKeyValue - sets pointer to first char
 * Return: returns pointer to first char
 * @key: key
 * @environ: value
 */
char *getKeyValue(char *key, char **environ)
{
	int i = 0;
	char *tmp = NULL;

	while (environ[i] && tmp == NULL)
	{
		tmp = _strstr(environ[i], key);
		i++;
	}

	tmp = _strstr(tmp, "="), tmp++;
	return (tmp);
}

/**
 * _strstr - locates a substring
 * Return: substring
 * @haystack: first string
 * @needle: substring to test against
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *ptr1 = haystack;
		char *ptr2 = needle;

		while (*haystack && *ptr2 && *haystack == *ptr2)
		{
			haystack++;
			ptr2++;
		}
		if (*ptr2 == '\0')
			return (ptr1);
		haystack = ptr1 + 1;
	}
	return (NULL);
}

/**
 * get_x_args - gets args
 * Return: return tmp if not equal to NULL
 * @tmp_args: temp args
 * @prog: program
 */
char *get_x_args(char **tmp_args, char *prog)
{
	int i = 1;
	char *tmp;

	tmp = _stralloc(3, tmp_args[0], "/", prog);
	while (access(tmp, X_OK) == -1 && tmp_args[i] != NULL)
	{
		free(tmp);
		tmp = _stralloc(3, tmp_args[i], "/", prog);
		i++;
	}
	if (tmp_args[i] == NULL)
		return (NULL);
	else
		return (tmp);
}

/**
 * _stralloc - mallocs proper amount of space
 * Return: pointer
 * @count: number of args
 */
char *_stralloc(int count, ...)
{
	va_list list;
	char *tmp_arg;
	char *tmp_ptr;
	char *tmp_return;
	int string_len;
	int arg_len;

	va_start(list, count);

	tmp_arg = va_arg(list, char *);
	count--;
	arg_len = _strlen(tmp_arg);

	tmp_return = malloc(sizeof(char) * arg_len + 1);
	if (tmp_return == NULL)
		exit(EXIT_FAILURE);

	_strcpy(tmp_return, tmp_arg);

	while (count != 0)
	{
		tmp_arg = va_arg(list, char *), count--;
		string_len = _strlen(tmp_return);
		arg_len = _strlen(tmp_arg);

		tmp_ptr = malloc(sizeof(char) * (string_len + arg_len) + 1);
		if (tmp_ptr == NULL)
			perror("check if second malloc failed");

		if (tmp_return != NULL)
		{
			_strcpy(tmp_ptr, tmp_return);
			free(tmp_return);
		}
		_strcat(tmp_ptr, tmp_arg);
		tmp_return = tmp_ptr;
	}

	va_end(list);
	return (tmp_return);
}
