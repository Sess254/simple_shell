#include "simple_shell.h"
/**
 * main - Main entry point
 * @argv: argument vector
 * @argc: argument counter
 * path_env: environment variable for the PATH
 * strtok: function to tokenize the PATH Variable
 * cmd_path: hold the path of the command
 * strcmp: function to compare the user input with exit command
 * Return: On sucess, 0.
 */
int main(int argc, char **argv)
{
	char *user_input, **args, *path, *cmd_path, *path_env, **paths;
	char *error_message = "No such file or directory\n";
	int count = 0;/*count of path*/
	(void)argc;
	path_env = getenv("PATH");
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
		user_input = get_input();
		/*Exit the shell when the user types exit*/
		if (_strcmp(user_input, "exit") == 0)
		{
			break;
		}
		args = input_tokenizer(user_input);
		/*Command in the paths search*/
		cmd_path = find_command(args[0], paths);
		if (cmd_path == NULL)
		{
			write(STDOUT_FILENO, argv[0], string_length(argv[0]));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, error_message, string_length(error_message));
		}
		else
		{
			execute_command(cmd_path, args);
		}
		free(user_input);
		free(args);
	}
	free(paths);
	return (0);
}
