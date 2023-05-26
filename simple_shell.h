#ifndef simple_shell_h
#define simple_shell_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024

extern char **environ;
void exit_shell(int status);
void handle_non_interactive_mode(char **paths);

/** String Functions for Copy, concatenate, length and compare*/
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
size_t string_length(const char *str);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *s1, const char *s2, size_t c);
char *_strdup(const char *str);

/*Function to get the environment*/
char *getenv(const char *name);

/*
 * Function to check if the input is from a terminal
 * int is_terminal();
 */

/* Function to read user input from stdin*/
char *get_input(char **paths);

/* Function to tokenize the user input*/
char **input_tokenizer(char *user_input);

/* Function for command search in the provided paths*/
char *find_command(char *cmd, char **paths);

/* Function to execute the command*/
void execute_command(char *cmd_path, char **args, char **envp);

#endif
