#include "main.h"
/**
 * _strlen - Returns the length of a string
 *
 * @s: The string
 *
 * Return: Length of s
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

char *_strcpy(char *copy, char *original)
{
	int i;

	for (i = 0; original[i] != '\0'; i++)
		copy[i] = original[i];

	copy[i] = '\0';

	return (copy);
}

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else
		return (s1[i] - s2[i]);
}

char *_strcat(char *string, char *addon)
{
	int i, j;

	for (i = 0; string[i] != '\0'; i++)
		;

	for (j = 0; addon[j] != '\0'; j++)
		string[i + j] = addon[j];

	string[i + j] = '\0';

	return (string);
}
