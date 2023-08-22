#include "main.h"

char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;
	char **variables_tokenized;

	while (environ[i] != NULL)
	{
		variables_tokenized = splitter(environ[i], "=");

		if (strcmp(variables_tokenized[0], name) == 0)
		{
			free(variables_tokenized);
			return environ[i];
		}
		else
		{
			free(variables_tokenized);
			i++;
		}
	}

	return (NULL);
}
