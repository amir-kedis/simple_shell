#include "hsh.h"
#include "list.h"

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

/**
 * is_chain_delim - check if character is a chain delimiter
 * @str: character to check
 * Return: chain delimiter or 0 if not
 */
int is_chain_delim(char *str)
{
	if (_strlen(str) < 2)
		return (0);
	if (str[0] == '|' && str[1] == '|')
		return (OR_DELIM);
	if (str[0] == '&' && str[1] == '&')
		return (AND_DELIM);
	if (str[0] == ';')
		return (SEMI_DELIM);
	return (0);
}
