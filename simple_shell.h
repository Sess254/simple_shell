#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <strings.h>
#include <stddef.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct builtins - struct with builtin commands
 * @argv: arg passed as command
 * @func: correlations function
 * description: this is to handle the builtins
 */
typedef struct builtins
{
	char *argv;
	int (*func)();
} builtins;

extern char **environ;
char **tokenize(char *userinput);
int stringlength(char *s);
int shell_loop(int argc, char **argv);
int executor(char *asdf, char **argv);
char *executable_maker(char *asdf, char **argv);
int function_finder(char **argv, char *buffer);
int sh_exit(char **argv, char *buffer);
int sh_cd(char **argv);
int sh_env(void);
char *_strcat(char *dest, char *src);
char *dir_search(char **argv, char **path_tokens);
int _strcmp(char *s1, char *s2);
void dub_free(char **dub_pointer);
int _putchar(char c);
char _strchr(char *s, char c);
char *_strdup(char *str);
char **_env_parser(char *name);
char **_get_env(char *env);
int sh_setenv(char **argv);
int sh_unsetenv(char **argv);

#endif
