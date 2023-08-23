#include "main.h"

char *_which(char* file)
{
	char *path, *file_path;
	char **path_tokenized;
	int i = 0, j;
	struct stat buffer;

	path = _getenv("PATH");

	if (path)
	{
		if (stat(file, &buffer) == 0)
			return (file);

		path_tokenized = splitter(path, ":");

		for (i = 0; path_tokenized != NULL; i++)
		{
			file_path = malloc(_strlen(file) + _strlen(path_tokenized[i]) + 2);
			_strcpy(file_path, path_tokenized[i]);
			_strcat(file_path, "/");
			_strcat(file_path, file);
			_strcat(file_path, "\0");
			
			if (stat(file_path, &buffer) == 0)
			{
				for (j = 0; path_tokenized[j] != NULL; j++)
					free(path_tokenized[j]);

				free(path_tokenized[j]);
				free(path_tokenized);

				return (file_path);
			}
			else
			{
				free(file_path);
			}
		}

		for (j = 0; path_tokenized[j] != NULL; j++)
			free(path_tokenized[j]);

		free(path_tokenized[j]);
		free(path_tokenized);
	}

	return(file);
				
}
