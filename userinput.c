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
 *_strdup - duplicates a string
 *@str: the string.
 *
 *Return: dup
 */
char *_strdup(const char *str)
{
	size_t len;
	char *dup;

	len = string_length(str) + 1;
	dup = malloc(len);

	if (dup != NULL)
		strcpy(dup, str);
	return (dup);
}
