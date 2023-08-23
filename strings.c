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

/**
 * _strcpy - Copies a string to another string
 *
 * @copy: The copied string
 * @original: The string to copy
 *
 * Return: The copied string
 */
char *_strcpy(char *copy, char *original)
{
	int i;

	for (i = 0; original[i] != '\0'; i++)
		copy[i] = original[i];

	copy[i] = '\0';

	return (copy);
}

/**
 * _strcmp - Compares two strings
 *
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 0 if they are equal,
 * otherwise the difference between the first and second string is returned
 */
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

/**
 * _strcat - Concatenates two strings
 *
 * @string: The first string
 * @addon: The second string
 *
 * Return: The resulting string after concatenation
 */
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
