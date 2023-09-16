#include "hsh.h"

/* FIXME: Code in this file is moved to builtin_lib_0.c */
/* DLELETE ME */
/**
 * exitcheck - Custom exit function with optional messages.
 * @s: An array of strings for optional exit messages.
 * @filename: name of the file
 * Return: exit code.
 */
int exitcheck(char **s, char *filename)
{
	int exitcode;

	if (s == NULL)
		return (-1);
	if (_strcmp(s[0], "exit\0") == 0)
	{
		if (s[1] == NULL)
			return (0);
		if (isnumerical(s[1]) == -1)
			exit_error(filename, 1, "exit", "Illegal number", 2, s[1]);
		exitcode = custom_atoi(s[1]);
		if (exitcode >= 0 && exitcode <= 255)
			return (exitcode);
		else if (exitcode > 255)
		{
			exitcode %= 256;
			return (exitcode);
		}
		else
		{
			exit_error(filename, 1, "exit", "Illegal number", 2, s[1]);
		}
	}
	return (-1);
}
