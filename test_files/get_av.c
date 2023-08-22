#include <stdio.h>

/**
 * main - Recieves a terminal input and prints it.
 * @ac: Input count.
 * @av: Array of inputs.
 * Return: 0
 */
int main(int ac, char **av)
{
	int i = 1;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}

	return (0);
}
