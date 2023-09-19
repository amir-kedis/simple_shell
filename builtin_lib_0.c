#include "hsh.h"
#include "list.h"
/**
* mycd - Change the current working directory
* @env: Pointer to the environment structure
* Return: 0 on success, non-zero on failure
*/
int mycd(env_t *env)
{
	char *curenv, *homedir, buffer[BUF_SIZE], *cderr;
	int chd;

	curenv = getcwd(buffer, BUF_SIZE);
	if (!curenv)
		_puts("??");
	if (env->token_arr[1] == NULL)
	{
		homedir = _getenvvar(env, "HOME=");
		if (!homedir)
		{
			homedir = _getenvvar(env, "PWD=");
			if (homedir)
				chd = chdir(homedir);
			else
				chd = chdir("/");
		}
		else
			chd = chdir(homedir);
	}
	else if (_strcmp(env->token_arr[1], "-") == 0)
	{
		homedir = _getenvvar(env, "OLDPWD=");
		if (!homedir)
		{
			_puts(curenv);
			_puts("\n");
			return (1);
		}
		else
		{
			_puts(homedir);
			_puts("\n");
			chd = chdir(homedir);
		}
	}
	else
		chd = chdir(env->token_arr[1]);
	cderr = malloc(2 + _strlen("can't cd to ") + _strlen(env->token_arr[1]));
	if (!cderr)
		return (-1);
	_strcpy("can't cd to \0", cderr);
	_strcat(cderr, env->token_arr[1]);
	if (chd == -1)
	{
		 exit_error(env->argv[0], 1, "cd", cderr, 2, NULL,env);
	}
	else
	{
		_setenvvar(env, "OLDPWD=", _getenvvar(env, "PWD="));
		_setenvvar(env, "PWD=", getcwd(buffer,1024));
	}
	return (1);
}
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
		{
			list_free(&(env->env_list));
			exit(env->last_exit_status);
		}

		if (isnumerical(s[1]) == -1)
		{
			exit_error(env->argv[0], 1, "exit", "Illegal number", 2, s[1], env);
			exit(2);
		}
		exitcode = custom_atoi(s[1]);
		if (exitcode >= 0 && exitcode <= 255)
		{
			list_free(&(env->env_list));
			exit(exitcode);
		}
		else if (exitcode > 255)
		{
			exitcode %= 256;
			list_free(&(env->env_list));
			exit(exitcode);
		}
		else
		{
			exit_error(env->argv[0], 1, "exit", "Illegal number", 2, s[1], env);
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

/**
 * builtin_setenv - builtin setenv function
 * @env: environment
 * Return: exit code
 */
int builtin_setenv(env_t *env)
{
	char *key, *value;
	char *key_value = NULL;
	list_t *node = NULL;

	if (env->token_arr[1] == NULL || env->token_arr[2] == NULL)
	{
		exit_error(env->argv[0], 1, "setenv", "Too few arguments", 2, NULL, env);
		return (0);
	}

	key = env->token_arr[1];
	value = env->token_arr[2];
	key_value = malloc(sizeof(char) * (_strlen(key) + _strlen(value) + 2));
	if (key_value == NULL)
		return (0);
	_strcpy(key, key_value);
	_strcat(key_value, "=");
	_strcat(key_value, value);

	if (env->env_list == NULL)
	{
		list_push(&(env->env_list), key_value);
		free(key_value);
		return (0);
	}

	node = list_find_node_starting_with(env->env_list, key);
	if (node != NULL)
	{
		free(node->str);
		node->str = key_value;
	}
	else
	{
		list_push(&(env->env_list), key_value);
		free(key_value);
	}
	return (0);
}

/**
 * builtin_unsetenv - builtin unsetenv function
 * @env: environment
 * Return: exit code
 */
int builtin_unsetenv(env_t *env)
{
	char *key;
	list_t *node = NULL;

	if (env->token_arr[1] == NULL)
	{
		exit_error(env->argv[0], 1, "unsetenv", "Too few arguments", 2, NULL, env);
		return (0);
	}

	key = env->token_arr[1];

	if (env->env_list == NULL)
		return (0);

	node = list_find_node_starting_with(env->env_list, key);

	if (node != NULL)
		list_delete_node(&(env->env_list), node);
	return (0);
}
