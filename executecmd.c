#include "simple_shell.h"

/* Function to execute the user input command*/

void execute_command(char *cmd_path, char **args) 
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
	    if (execve(cmd_path, args, NULL) == -1)
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
