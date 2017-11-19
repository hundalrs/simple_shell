#include "holberton.h"

/**
 * _strlen - returns the length of a string
 * Return: counter
 * @s: string being passed to count length
 */

int _strlen(char *s)
{
	int counter = 0;

	while (s[counter])
	{
		counter++;
	}
	return (counter);

}
