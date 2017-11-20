#include "holberton.h"

/**
 * main - entry function
 * Return: 1 if successful
 */
int main(void)
{
	int status;

	do {
		status = main_shell();
	} while (status != EXIT_SHELL);

	return (1);
}
