#include "main.h"
/**
 * main - Entry Point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *buffer = NULL, *full_command = NULL;
	char **argv;
	size_t characters, num = 0;
	pid_t child_pid = 1;
	int status, i;

	while (1 == 1)
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			if (isatty(0) == 1)
				_printf("$ ");

			characters = getline(&buffer, &num, stdin);

			if ((int)characters == -1)
			{
				if (isatty(0) == 1)
					_printf("Exiting shell...\n");

				free(buffer);
				exit(2);
			}

			argv = splitter(buffer, " \n");
			full_command = _which(argv[0]);

			if (execve(full_command, argv, environ) == -1)
				_perror("");

			for (i = 0; argv[i] != NULL; i++)
			{
				free(argv[i]);
			}

			free(argv[i]);
			free(argv);
			free(buffer);

			return (0);
		}
		else
		{
			wait(&status);

			if (status == 512)
			{
				free(buffer);
				return (0);
			}
		}
	}
}
