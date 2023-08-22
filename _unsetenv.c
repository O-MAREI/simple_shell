#include "main.h"

int _unsetenv(const char *name)
{
	extern char **environ;
	size_t str_len = strlen(name);

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	
	str_len = strlen(name);
	
	for (char **ep = environ; *ep != NULL;)
	{
		if (strncmp(*ep, name, str_len) == 0 && (*ep)[str_len] == '=')
		{
			for (char **sp = ep; *sp != NULL; sp++)
				*sp = *(sp + 1);
		}
		else 
		{
			ep++;
		}
	}

	return (0);
}
