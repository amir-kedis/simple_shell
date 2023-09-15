#include"hsh.h"

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
