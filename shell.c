#include "main.h"
/**
 * main - Simple Shell
 *
 * Return: 0 (Success) | 2 (Failure)
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

			if ((int)characters == -1 || is_exit(buffer) != 0)
			{
				free(buffer);
				if (is_exit(buffer) == 1)
					exit(1);
				exit(2);
			}

			argv = splitter(buffer, " \n");

			if (_strcmp(argv[0], "env") == 0)
			{
				print_environ();
				return (0);
			}

			for (i = 0; argv[i] != NULL; i++)
			{
				full_command = _which(argv[i]);
				if (full_command != NULL)
				{
					if (execve(full_command, argv, environ) == -1)
					{
						_perror("");
					}
				}

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
			errno = WIFEXITED(status);

			if (status == 512)
			{
				free(buffer);
				return (2);
			}
			else if (status == 139)
				return (0);
		}
	}
}

/**
 * is_exit - Checks if user input exit command
 * @buffer: Buffer holding user input
 *
 * Return: 0 - No Exit | 1 - Exit | 3 = Args
 */
int is_exit(char *buffer)
{
	char *exit = "exit";
	char **argv;
	int i, flag = 0;

	argv = splitter(buffer, " \n");

	if (_strcmp(argv[0], exit) == 0)
	{
		if (argv[1] == NULL)
			flag = 1;
		else
		{
			flag = 3;
		}


		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free(argv[i]);
	}
	else
	{
		flag = 0;
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free(argv[i]);
	}

	free(argv);
	return (flag);
}
