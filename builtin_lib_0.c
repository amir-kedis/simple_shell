#include "hsh.h"
#include "list.h"

/**
 * builtin_exit - builtin exit function
 * @env: environment
 * Return: exit code
 */
int builtin_exit(env_t *env)
{
	int exitcode;
	char **s;

	s = env->token_arr;
	if (s == NULL)
		return (-1);
	if (_strcmp(s[0], "exit\0") == 0)
	{
		if (s[1] == NULL)
			exit(env->last_exit_status);

		if (isnumerical(s[1]) == -1)
			exit_error(env->argv[0], 1, "exit", "Illegal number", 2, s[1]);
		exitcode = custom_atoi(s[1]);
		if (exitcode >= 0 && exitcode <= 255)
		{
			exit(exitcode);
		}
		else if (exitcode > 255)
		{
			exitcode %= 256;
			exit(exitcode);
		}
		else
		{
			exit_error(env->argv[0], 1, "exit", "Illegal number", 2, s[1]);
		}
	}
	return (-1);
}

/**
 * builtin_env - builtin env function
 * @env: environment
 * Return: exit code
 */
int builtin_env(env_t *env)
{
	if (env->env_list == NULL)
		return (-1);

	list_print(env->env_list);

	return (0);
}
