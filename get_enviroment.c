#include "simple_shell.h"

/**
 *getenv - gets the enviroment
 *@name: the enviroment
 *
 *Return: the enviroment
 */
char *getenv(const char *name)
{

	size_t name_len;
	char **env = environ;

	name_len = string_length(name);

	while (*env != NULL)
	{
		if (strcmp(*env, name, name_len) == 0 && (*env)[name_len]
				== '=')
		{
			return (&((*env)[name_len + 1]));
		}
		env++;
	}
	return (NULL);
}
