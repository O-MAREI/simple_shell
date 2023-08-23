#include "main.h"

int _setenv(const char *name, const char *value, int overwrite)
{
	char *variable;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL ||
			value == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	
	if (_getenv(name) != NULL && overwrite == 0)
		return (0);

	_unsetenv(name);
	variable = malloc(strlen(name) + strlen(value) + 2);
	
	if (variable == NULL)
		return (-1);
	
	strcpy(variable, name);
	strcat(variable, "=");
	strcat(variable, value);

	if (putenv(variable) != 0)
		return (-1);
	else
		return (0);
}
