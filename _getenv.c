#include "main.h"

/**
 * _getenv - Gets environment variable
 * @name: name of environment variable
 *
 * Return: The environment variable
 */
char *_getenv(char *name)
{
	int i = 0, j;
	char **variables_tokenized;

	while (environ[i] != NULL)
	{
		variables_tokenized = splitter(environ[i], "=");

		if (_strcmp(variables_tokenized[0], name) == 0)
		{
			for (j = 0; variables_tokenized[j] != NULL; j++)
				free(variables_tokenized[j]);

			free(variables_tokenized[j]);
			free(variables_tokenized);

			return (environ[i]);
		}
		else
		{
			for (j = 0; variables_tokenized[j] != NULL; j++)
				free(variables_tokenized[j]);

			free(variables_tokenized[j]);
			free(variables_tokenized);
			i++;
		}
	}

	return (NULL);
}
