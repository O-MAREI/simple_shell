#include "main.h" 
void print_dirs()
{
	char *path = _getenv("PATH");
	char **dirs = splitter(path, "=");
	char **dirs_tokenized = splitter(dirs[1], ":");
	int i = 0;

	while (dirs_tokenized[i] != NULL)
		printf("%s\n", dirs_tokenized[i++]);

	free(dirs);
	free(dirs_tokenized);
}
