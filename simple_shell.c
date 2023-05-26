#include "simple_shell.h"
/**
 * main - Main entry point
 * @argv: argument vector
 * @argc: argument counter
 * @envp: enviro
 * Return: On sucess, 0.
 */
int main(int argc, char **argv, char **envp)
{
	char *user_input, **args, *path, *cmd_path, *path_env, **paths;
	int count = 0;/*count of path*/

	path_env = getenv("PATH");
	(void)argc;
	(void)argv;
	paths = malloc(BUFFER_SIZE * sizeof(char *));
	path = strtok(path_env, ":");
	while (path != NULL)
	{
		paths[count] = path;
		path = strtok(NULL, ":");
		count++;
	}
	paths[count] = NULL;
	while (1)
	{
		user_input = get_input(paths);
		fflush(stdout);
		if (_strcmp(user_input, "exit") == 0)
		{
			exit_shell(0);
		}
		args = input_tokenizer(user_input);
		cmd_path = find_command(args[0], paths);
		if (cmd_path == NULL)
		{
			continue;

		}
		else
		{
			execute_command(cmd_path, args, envp);
		}
		free(cmd_path), free(args);
	}
	free(path), free(path_env);
	return (0);
}
