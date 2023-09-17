#include "hsh.h"

/**
 * remove_comments - remove comments from line
 * @line: line to remove comments from
 * Return: void
 */
void remove_comments(char *line)
{
	int i;

	for (i = 0; line[i]; i++)
		if (line[i] == '#' && (i == 0 || line[i - 1] == ' '))
		{
			line[i] = '\0';
			return;
		}
}
