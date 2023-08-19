#include <stdio.h>
#include <stdlib.h>

/**
 * main - Simulates terminal input prompt "$ ",
 * reads user input and prints it to stdout.
 */
int main()
{
	char *buffer = NULL;
	size_t characters, num = 0;

	printf("$ ");
	characters = getline(&buffer, &num, stdin);

	if (characters != 1)
		printf("%s", buffer);
	else
		printf("Error.");

	free(buffer);

	return (0);
}
