#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	ssize_t num_characters;
	char *str = NULL;
	size_t n = 0;
	char *my_char = "lol you are gay";

	printf("$ " );
	num_characters = getline(&str, &n, stdin);
	printf("getline results: %ld\n", num_characters);

	printf("strlen results: %ld\n", strlen(my_char));
	return (0);
}
