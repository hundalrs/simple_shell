#include "holberton.h"

int main()
{
	int status;

	do {
		status = main_shell();
	} while (status != EXIT_SHELL);

        return (1);
}
