#include "hsh.h"

/**
 * builtin_mux - matches a builtin to a function
 * @builtin: builtin to match
 * Return: pointer to builtin function
 */
int (*builtin_mux(char *builtin))(env_t *env)
{
	builtin_t builtin_arr[] = {{"exit", builtin_exit},
														 {"env", builtin_env},
														 {"setenv", builtin_setenv},
														 {"unsetenv", builtin_unsetenv},
														 {"cd", mycd},
														 {"alias", myalias},
														 {NULL, NULL}};
	int i;

	i = 0;
	while (builtin_arr[i].builtin != NULL)
	{
		if (_strcmp(builtin_arr[i].builtin, builtin) == 0)
			return (builtin_arr[i].func);
		i++;
	}
	return (NULL);
}
