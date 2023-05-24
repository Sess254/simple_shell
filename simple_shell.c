#include "simple_shell.h"

int main() 
{
    /**int terminal = is_terminal();*/
    char *user_input;
    char **args;
    char *path;
    char *cmd_path;
    char *path_env;
    char **paths;
    int count = 0;/*count of path*/

    /* Getting the PATH environment variable*/
    path_env = getenv("PATH");

    /*Memory Allocation to paths*/
    paths = malloc(BUFFER_SIZE * sizeof(char *));

    /*Tokenizining the PATH variable*/
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

        if (strcmp(user_input, "exit") == 0) 
	{
            break;
        }

        args = input_tokenizer(user_input);

        /*Command in the paths search*/
        cmd_path = find_command(args[0], paths);

        if (cmd_path == NULL) 
	{
            write(STDOUT_FILENO, "No such file or directory \n", 25);
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
