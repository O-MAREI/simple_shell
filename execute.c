#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *argv[] = {"../bin/ls", "-l", "/tmp", NULL};
	pid_t child_pid = 1;
	int status, i;

	for (i = 0; i < 6; i++)
	{
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
			return (0);
		}
		else
		{
			wait(&status);
			child_pid = fork();
		}
	}

	return (0);
}
