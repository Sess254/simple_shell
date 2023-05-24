#include "simple_shell.h"

/**
 *find_command - function to find commands in sh
 *@cmd: command
 *@paths: the paths
 *
 *Return: the command
 */
char *find_command(char *cmd, char **paths)
{
	char *path;
	char *full_path;
	int i = 0;
	char *result;

	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
		{
			result = strdup(cmd);
			if (!result)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
			return (result);
		}
		return (NULL);
	}


	full_path = malloc(BUFFER_SIZE);

	while ((path = paths[i++]) != NULL)
	{
		strcpy(full_path, path);
		strcat(full_path, "/");
		strcat(full_path, cmd);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
	}
	free(full_path);
	return (NULL);
}
