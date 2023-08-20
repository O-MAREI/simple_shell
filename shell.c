#include "main.h"

int main(void)
{
	char *buffer = NULL;
	char **argv;
	size_t /*characters, */ num = 0;

	printf("$ ");
	getline(&buffer, &num, stdin);

	/*Adjust splitter so it recieves the return value of getline */
	argv = splitter(buffer);
	
	if (execve(argv[0], argv, NULL) == -1)
		perror("Error");
	
	printf("NULL\n");
           
	free(argv);
        free(buffer);

        return (0);
}
