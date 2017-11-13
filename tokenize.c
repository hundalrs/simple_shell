#include "holberton.h"

char **tokenizer (char **buffer)
{
        char *tok;
	char **_argv;
        int i;

        tok = strtok (*buffer, " \n\t");
        if (tok == NULL)
                perror ("Could not tokenize commands");
        _argv = malloc(sizeof(char *) * 2);
        if (_argv == NULL)
                exit (0);

        _argv[0] = tok;
        i = 1;
        while (tok != NULL)
        {
                tok = strtok(NULL, " \n\t");
                if (tok != NULL)
                {
			_argv = realloc(_argv, sizeof (char*) * (i + 2));
			if (_argv == NULL)
                        {
                                free (buffer);
                                perror("Could not realloc");
                                exit (0);
                        }
                        _argv[i] = tok;
                        i++;
                }
        }
        _argv[i] = NULL;
	return (_argv);
}


void _exec_process(char **_argv)
{

        pid_t pid;

        pid = fork();

        if (pid == -1)
                perror("Could not fork");
        if (pid == 0)
        {
                if (execve(_argv[0], _argv, NULL) == -1)
                {
                        perror("error in execute command");
                }
                exit(EXIT_FAILURE);
        }

}
