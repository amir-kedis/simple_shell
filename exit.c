#include"hsh.h"
/**
* exitcheck - Custom exit function with optional messages.
* @s: An array of strings for optional exit messages.
*
* Return: exit code.
*/
int exitcheck(char **s)
{
	int exitcode; 

	if (s == NULL)
		return (-1);
	if (_strcmp(s[0], "exit\0") == 0)
	{
		if (s[1] == NULL)
			return (0);
		if (isnumerical(s[1]) == -1)
			return (2);
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
			return (2);
		}
	}
	return (2);
}
