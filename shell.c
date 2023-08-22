#include "main.h"

int main(void)
{
	char *buffer = NULL, *full_command = NULL;
	char **argv;
	size_t /*characters, */ num = 0;
	pid_t child_pid = 1;
        int status;

	while (1 == 1)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			printf("$ ");
			getline(&buffer, &num, stdin);

			/* Adjust splitter so it recieves the return value of getline */
			argv = splitter(buffer, " \n");
			full_command = _which(argv[0]);

			if (execve(full_command , argv, NULL) == -1)
				perror("Error");
			
			return (0);
		}
		else
		{
			wait(&status);
		}
	}

	free(argv);
        free(buffer);

        return (0);
}
