#include "main.h"
/**
 * main - Entry point
 *
 * @ac: Number of command line arguments
 * @av: Array of string pointers containing command line arguments
 *
 * Return: 0 (Success), -1 (Fail)
 */
int main(int ac, char **av)
{
	char *prompt;
	char *line, *cpline, *tok;
	size_t size;
	ssize_t nchars;
	int ntok, i;
	(void)ac;

	while (1)
	{
		prompt = "($) ";
		size = 0;
		printf("%s", prompt);
		nchars = getline(&line, &size, stdin);

		if (nchars == -1)
		{
			printf("Exiting shell...\n");
			return (-1);
		}

		cpline = malloc(sizeof(char) * nchars);
		if (cpline == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(cpline, line);
		ntok = 0;
		tok = strtok(cpline, " \n");
		while (tok != NULL)
		{
			ntok++;
			tok = strtok(NULL, " \n");
		}
		ntok++;
		av = malloc(sizeof(char *) * ntok);
		tok = strtok(line, " \n");
		for (i = 0; tok != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(tok));
			strcpy(av[i], tok);
			tok = strtok(NULL, " \n");
		}
		av[i] = NULL;

		

		/*printf("%s\n", line);*/
		free(av);
		free(cpline);
		free(line);
	}

	return (0);
}
