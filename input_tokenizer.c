#include "simple_shell.h"

/**
 * *input_tokenizer - Function to tokenize the input
 * @user_input: hold user input
 *
 * Return: a pointer to the next token, or NULL if there are no more tokens
 */

char **input_tokenizer(char *user_input)
{
	char **args;
	char *token;
	int m;
	/*memory allocation */
	args = malloc(BUFFER_SIZE * sizeof(char *));
	token = strtok(user_input, " ");
	/*Tokenize*/
	m = 0;
	while (token != NULL)
	{
		args[m] = token;
		token = strtok(NULL, " ");
		m++;
	}
	args[m] = NULL;
	return (args);
}

