#include "hsh.h"
#include <errno.h>
#include <stdio.h>

/**
 * execute_command - executes a command
 * @args: arguments to execute
 * @env: environment variables
 * @ob_name: file executable name
 * Return: void
 */
void execute_command(char **args, char **env, char *ob_name)
{
	pid_t pid;
	int status;
	char *cmd_path = get_path(args[0], environ);

	(void) env;
	if (args[0] == NULL || args[0][0] == '\0' || args[0][0] == '\n')
		return;
	if (exitcheck(args, ob_name) >= 0)
		exit(exitcheck(args, ob_name));
	if (printenv(args, ob_name, environ))
		return;

	if (cmd_path == NULL)
	{
		exit_error(ob_name, 1, args[0], "not found", 127, NULL);
		return;
	}
	pid = fork();
	if (pid == 0) /* child process */
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			exit_error(ob_name, 1, "", "", 127, NULL);
			free(cmd_path);
			return;
		}
		exit(EXIT_FAILURE);
	}
	else if (pid == -1) /* error forking */
		perror("Error forking");
	else /* parent process */
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		free(cmd_path);
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

	token = strtok(path, ":");
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
		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
