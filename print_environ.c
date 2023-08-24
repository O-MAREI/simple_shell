#include "main.h"

/**
 * print_environ - Prints environment
 *
 * Return: 0;
 */
int print_environ(void)
{
	int i = 0;

	while (environ[i])
		printf("%s\n", environ[i++]);

	return (0);
}
