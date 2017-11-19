#include "holberton.h"

char *getPathArgs(char *prog, char **environ)
{
	char *tmp;
	char **tmp_args;

	tmp = getKeyValue("PATH", environ);
	tmp_args = tokenizer(&tmp, ":");
	tmp = get_x_args(tmp_args, prog);

	free(tmp_args);
	return (tmp);
}

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

char *get_x_args(char **tmp_args, char *prog)
{
	int i = 1;
	char *tmp;

	tmp = allocate_strings(3, tmp_args[0], "/", prog);
	while (access(tmp, X_OK) == -1 && tmp_args[i] != NULL)
	{
		free(tmp);
		tmp = allocate_strings(3, tmp_args[i], "/", prog);
		i++;
	}
	if (tmp_args[i] == NULL)
		return (NULL);
	else
		return (tmp);
}

char *allocate_strings (int count, ...)
{
	va_list list;
	char *tmp_arg;
	char *tmp_ptr;
	char *tmp_return;
	int sLen;
	int aLen;

	va_start(list, count);

	tmp_arg = va_arg(list, char *);
	count--;
	aLen = _strlen(tmp_arg);

	tmp_return = malloc(sizeof(char) * aLen + 1);
	if (tmp_return == NULL)
		exit (EXIT_FAILURE);

	_strcpy(tmp_return, tmp_arg);

	while (count != 0)
	{
		tmp_arg = va_arg(list, char *), count--;
		sLen = _strlen(tmp_return);
		aLen = _strlen(tmp_arg);

		tmp_ptr = malloc(sizeof(char) * (sLen + aLen) + 1);
		if (tmp_ptr == NULL)
			perror("check if second malloc failed");

		if (tmp_return != NULL)
			_strcpy(tmp_ptr, tmp_return), free(tmp_return);
		_strcat(tmp_ptr, tmp_arg);
		tmp_return = tmp_ptr;
	}

	va_end(list);
	return (tmp_return);
}
