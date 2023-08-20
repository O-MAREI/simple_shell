#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **splitter(char *str)
{
	char **strings;
	int index, count = 0;
	char *delimiter = " ", *token, *str_copy, *second_copy;


	str_copy = malloc(sizeof(char) * (strlen(str) + 1));
	strcpy(str_copy, str);

	token = strtok(str_copy, delimiter);

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delimiter);
	}

	count++;

	/* Another copy to avoid modificiation of string literal*/
	second_copy = malloc(sizeof(char) * (strlen(str) + 1));
	strcpy(second_copy, str);

	/* Dynamic memory allocation for string of strings */
	strings = malloc(sizeof(char *) * count);
	token = strtok(second_copy, delimiter);

	/* Parsing the rest of the strings and allocating their memory */
	for (index = 0; token != NULL; index++)
	{
		strings[index] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(strings[index], token);
		token = strtok(NULL, delimiter);
	}

	/* Null termination */
        strings[index] = NULL;

	free(str_copy);

	return (strings);
}


int main()
{
	char **strings = splitter("2dlm 40 eroi lerk");
	int i;

	for (i = 0; strings[i] != NULL; i++)
	{
		printf("%d, %s\n", i, strings[i]);
		free(strings[i]);
	}

	free(strings);

	return (0);
}
