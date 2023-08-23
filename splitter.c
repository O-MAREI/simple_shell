#include "main.h"

char **splitter(char *str, char *delim)
{
	char **strings;
	int index, count = 0;
	char *delimiter = delim, *token, *str_copy, *second_copy;


	str_copy = malloc(sizeof(char) * (_strlen(str) + 1));
	_strcpy(str_copy, str);

	token = strtok(str_copy, delimiter);

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delimiter);
	}

	count++;

	/* Another copy to avoid modificiation of string literal*/
	second_copy = malloc(sizeof(char) * (_strlen(str) + 1));
	_strcpy(second_copy, str);

	/* Dynamic memory allocation for string of strings */
	strings = malloc(sizeof(char *) * count);
	token = strtok(second_copy, delimiter);

	/* Parsing the rest of the strings and allocating their memory */
	for (index = 0; token != NULL; index++)
	{
		strings[index] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(strings[index], token);
		token = strtok(NULL, delimiter);
	}

	/* Null termination */
	 strings[index] = NULL;

	free(str_copy);
	free(second_copy);

	return (strings);
}
