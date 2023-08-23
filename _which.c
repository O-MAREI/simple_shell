#include "main.h"

char *_which(char* file)
{
	char *path, *file_path;
	char **path_tokenized;
	int i = 0;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		if (stat(file, &buffer) == 0)
			return (file);

		path_tokenized = splitter(path, ":");

		for (i = 0; path_tokenized != NULL; i++)
		{
			file_path = malloc(strlen(file) + strlen(path_tokenized[i]) + 2);
			strcpy(file_path, path_tokenized[i]);
			strcat(file_path, "/");
			strcat(file_path, file);
			strcat(file_path, "\0");
			
			if (stat(file_path, &buffer) == 0)
			{
				free(path_tokenized);
				return (file_path);
			}
			else
			{
				free(file_path);
			}
		}

		free(path_tokenized);
	}

	return(file);
				
}
