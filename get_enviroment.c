#include "simple_shell.h"

/**
 * _get_env - gets the current env
 * @env: the enviroment
 * Return: _env_parser function on success, NULL
**/
char **_get_env(char *env)
{
	int in;
	int out;
	char *name = NULL;

	for (out = 0; environ[out] != NULL; out++)
	{
		for (in = 0; environ[out][in] != '='; in++)
		{
			if (environ[out][in] != env[in])
				break;
			if (environ[out][in] == env[in])
			{
				if (env[in + 1] == '\0' && environ[out][in + 1] == '=')
				{
					name = _strdup(&(environ[out][in + 2]));
					return (_env_parser(name));
				}
			}
		}
	}
	return (NULL);
}

/**
 * _env_parser- tokenizes the PATH
 * @name: the full PATH
 * Return: an array of strings
**/
char **_env_parser(char *name)
{
	int token_inc;
	int tokencount;
	char *tokenize = NULL;
	int i;
	char **p = NULL;
	char *namestore = name;

	tokencount = 0;
	for (i = 0; name[i] != '\0'; i++)
	{
		if (name[i] == ':')
		{
			tokencount++;
		}
	}
	p = malloc(sizeof(char *) * (tokencount + 2));
	if (p != NULL)
	{
		token_inc = 0;
		tokenize = strtok(name, ":");
		while (token_inc < (tokencount + 1))
		{
			p[token_inc] = _strdup(tokenize);
			tokenize = strtok(NULL, ":");
			token_inc++;
		}
	p[token_inc] = NULL;
	}
	free(namestore);
	return (p);
}
