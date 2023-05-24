#ifndef simple_shell_h
#define simple_shell_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/** String Functions for Copy, concatenate, length and compare*/
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
size_t string_length(const char *str);
int strcmp(const char *str1, const char *str2);

/*Function to get the environment*/
char *getenv(const char *name);

/* Function to check if the input is from a terminal
int is_terminal();
*/
/* Function to read user input from stdin*/
char *get_input();

/* Function to tokenize the user input*/
char **input_tokenizer(char *user_input);

/* Function for command search in the provided paths*/
char *find_command(char *cmd, char **paths);

/* Function to execute the command*/
void execute_command(char *cmd_path, char **args);

#endif
