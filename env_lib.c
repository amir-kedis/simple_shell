#include "hsh.h"
/**
 * _getenv - gets an environment variable
 * @name: name of the variable
 * @env: environment variables (If NULL, uses global variable)
 * Return: value of the variable
 */
char *_getenv(char *name, char **env)
{
	int i;
	char *token;
	char *value;
	char **env_copy;
	char *env_name;

	if (env == NULL)
		env_copy = copy_str_array(__environ);
	else
		env_copy = copy_str_array(env);
	for (i = 0; env_copy[i] != NULL; i++)
	{
		token = _strtok(env_copy[i], "=");
		if (_strcmp(token, name) == 0)
		{
			value = _strtok(NULL, "=");
			if (value == NULL)
			{
				free_str_array(env_copy);
				return (NULL);
			}
			env_name = _strdup(value);
			free_str_array(env_copy);
			env_copy = NULL;
			return (env_name);
		}
	}

	free_str_array(env_copy);
	return (NULL);
}
