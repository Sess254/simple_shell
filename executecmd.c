#include "simple_shell.h"

/**
 * execute_command - Function to execute the user input command
 * @cmd_path: Command path
 * @args: Command arguments
 *
 * Return: On success, return NULL
 */


void execute_command(char *cmd_path, char **args, char **evnp)
{
	pid_t child_process;
	int status;

/*Forking the child process*/
	child_process = fork();
	if (child_process == -1)
	{
		perror("Failed to fork");
		exit(EXIT_FAILURE);
	}
	else if (child_process == 0)
	{
/* Execute command using exceve*/
		if (execve(cmd_path, args, evnp) == -1)
		{
			perror("Failed to execute");
			exit(EXIT_FAILURE);
		}
/* exit(EXIT_SUCCESS);*/
	}
	else
	{
/*Parent process*/
		waitpid(child_process, &status, 0);
	}
}
