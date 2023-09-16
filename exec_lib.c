#include "hsh.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * execute_command - executes a command
 * @env: environment variables and tokens
 * Return: void
 */
void execute_command(env_t *env)
{
	pid_t pid;
	int status;
	char *cmd_path;

	if (env->token_arr[0] == NULL || env->token_arr[0][0] == '\0' ||
			env->token_arr[0][0] == '\n')
		return;
	if (builtin_mux(env->token_arr[0]) != NULL)
	{
		builtin_mux(env->token_arr[0])(env);
		return;
	}
	cmd_path = get_path(env->token_arr[0], env->env);
	if (cmd_path == NULL)
	{
		exit_error(env->argv[0], 1, env->token_arr[0], "not found", 127, NULL);
		return;
	}
	pid = fork();
	if (pid == 0) /* child process */
	{
		if (execve(cmd_path, env->token_arr, env->env) == -1)
		{
			exit_error(env->argv[0], 1, "", "", 127, NULL);
			free(cmd_path);
			return;
		}
		exit(EXIT_FAILURE);
	}
	else if (pid == -1) /* error forking */
		perror("Error forking");
	else /* parent process */
	{ /* clang-format off */
		do {	 /* clang-format on */
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		free(cmd_path);
		env->last_exit_status = WEXITSTATUS(status);
	}
}

/**
 * get_path - gets the path of a command
 * @command: command to get path of
 * @env: environment variables
 * Return: path of command or the same command if it is already a path
 * or NULL if not found
 */
char *get_path(char *command, char **env)
{
	char *path;
	char *token;
	char *full_path;

	if (command == NULL)
		return (NULL);
	if (command[0] == '/' || command[0] == '.')
		return (_strdup(command));

	path = _getenv("PATH", env);
	if (path == NULL || path[0] == '\0' || path[0] == '\n')
		return (NULL);

	token = _strtok(path, ":");
	while (token != NULL)
	{
		full_path = malloc(sizeof(char) * (_strlen(token) + _strlen(command) + 2));
		if (full_path == NULL)
			return (NULL);

		_strcpy(token, full_path);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (full_path);
		}

		free(full_path);
		token = _strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
