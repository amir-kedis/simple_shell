#include "hsh.h"

/**
 * _getenv - gets an environment variable
 * @name: name of the variable
 * @env: environment variables (If NULL, uses global variable)
 * Return: value of the variable
 */
char *_getenv(char *name, char **env)
{
	/* TODO: may have to change gow it works after changing env hnadling */
	int i;
	char *token;
	char *value;
	char **env_copy;

	if (env == NULL)
		env_copy = copy_str_array(__environ);
	else
		env_copy = copy_str_array(env);

	for (i = 0; env_copy[i] != NULL; i++)
	{
		token = strtok(env_copy[i], "=");
		if (_strcmp(token, name) == 0)
		{
			value = strtok(NULL, "=");
			return (value);
		}
	}

	free_str_array(env_copy);
	return (NULL);
}
