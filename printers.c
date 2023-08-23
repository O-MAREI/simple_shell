#include "main.h"
/**
 * _printf - Prints a string
 *
 * @str: The string to be printed
 */
void _printf(char *str)
{
	size_t len;
	ssize_t num;

	len = _strlen(str);
	num = write(1, str, len);
	if (num == -1)
	{
		_perror("write");
	}
}

/**
 * _perror - Prints and error message
 *
 * @message: The message to be printed
 */
void _perror(char *message)
{
	size_t len;
	ssize_t num;

	len = _strlen(message);
	num = write(2, message, len);

	if (num == -1)
	{
		_perror("write");
	}
}
