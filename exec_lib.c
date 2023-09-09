#include "hsh.h"

/**
 * execute_command - executes a command
 * @args: arguments to execute
 * @env: environment variables
 * Return: void
 */
void execute_command(char **args, char **env)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
		return;

	pid = fork();
	if (pid == 0) /* child process */
	{
		if (execve(args[0], args, env) == -1)
		{
			return;
		}
		exit(EXIT_FAILURE);
	}
	else if (pid == -1) /* error forking */
	{
		perror("Error forking");
	}
	else /* parent process */
	{
		/* clang-format off */
		do {
			/* clang-format on */
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		free(args);
	}
}
