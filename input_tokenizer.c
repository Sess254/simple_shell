#include "simple_shell.h"


/* Function to tokenize the input*/
char **input_tokenizer(char *user_input) 
{
	char **args;
	char *token;
	int m;
	
	args = malloc(BUFFER_SIZE * sizeof(char *));
	token = strtok(user_input, " ");
	
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

