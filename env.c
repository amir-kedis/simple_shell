#include"hsh.h"
/*
* printenv - Write environment variables to a file
* @s: File descriptor for the output file
* @file_name: Name of the file to write to
* @env: Array of environment variables (null-terminated)
* Return: Number of variables written, or -1 on error
*/
int printenv(char **s, char *file_name, char **env)
{
	int i;

	(void)file_name;
	(void)env;
	i = 0;
	if (!s || !env)
		return (0);
	if (_strcmp(s[0], "env\0") == 0)
	{
		while (environ[i])
		{
			_puts_fd(environ[i], STDOUT_FILENO);
			_puts_fd("\n", STDOUT_FILENO);
			i++;
		}
		return (1);
	}
	else
		return (0);
}
