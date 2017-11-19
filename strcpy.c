#include "holberton.h"

/**
 * _strcpy - wrote a function that copies string by src
 * Return: dest
 * @dest: pointer being passed
 * @src: pointer being passed
 */

char *_strcpy(char *dest, char *src)
{
	int size, i;

	size = 0;
	while (src[size])
	{
		size++;
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';

	return (dest);
}
