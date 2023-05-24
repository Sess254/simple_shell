#include "simple_shell.h"

/**
 * get_input - Function to read user input
 *
 * Return: On success,return the number of characters read
 */

char *get_input()
{
	char *user_input = NULL;
	size_t size_of_input = 0;
	ssize_t length_of_input;
	/* getline function*/
	if (isatty(STDOUT_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	length_of_input = getline(&user_input, &size_of_input, stdin);
	if (length_of_input == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		perror("No such file or directory \n");
		write(STDOUT_FILENO, "\n", 1); /*Push the prompt to a new line*/
		exit(EXIT_FAILURE);
	}
	/*Remove the newline character at the end*/
	if (length_of_input > 0 && user_input[length_of_input - 1] == '\n')
		user_input[length_of_input - 1] = '\0';
	return (user_input);
}
/**
 *handle_non_interactive_mode - handles non-interactive mode
 *@paths: paths
 *
 *Return: void
 */
void handle_non_interactive_mode(char **paths)
{
	char *command;
	char **args, *cmd_path;

	command = "/bin/ls";

	args = input_tokenizer(command);
	cmd_path = find_command(args[0], paths);

	if (cmd_path == NULL)
	{
		write(STDOUT_FILENO, "No such file or dirctory\n", 26);
		exit(EXIT_FAILURE);
	}
	else
	{
		execute_command(cmd_path, args);
	}

	free(args);
}
