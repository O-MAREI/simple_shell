#include "main.h"
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
