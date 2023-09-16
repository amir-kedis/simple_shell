#include "hsh.h"
/**
 * free_str_array - free a string array
 * @str_array: string array to free
 * Return: void
 */
void free_str_array(char **str_array)
{
	int i = 0;

	if (str_array == NULL)
		return;
	for (i = 0; str_array[i] != NULL; i++)
	{
		if (str_array[i] != NULL)
			free(str_array[i]);
		str_array[i] = NULL;
	}
	free(str_array);
	str_array = NULL;
}

/**
 * is_delim - checks if a character is a delimiter
 * @c: character to check
 * @delim: delimiters
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	int i;

	for (i = 0; delim[i] != '\0'; i++)
		if (c == delim[i])
			return (1);

	return (0);
}

/**
 * _strtok - tokenizes a string
 * @str: string to tokenize
 * @delim: delimiters
 * Return: pointer to next token
 */
char *_strtok(char *str, char *delim)
{
	static char *next;
	char *token;

	if (str == NULL)
		str = next;
	if (str == NULL)
		return (NULL);
	while (1)
	{
		if (is_delim(*str, delim))
		{
			str++;
			continue;
		}
		if (*str == '\0')
		{
			next = NULL;
			return (NULL);
		}
		break;
	}
	token = str;
	while (*str != '\0')
	{
		if (is_delim(*str, delim))
		{
			*str = '\0';
			next = str + 1;
			return (token);
		}
		if (*str == '\0')
		{
			next = NULL;
			return (token);
		}
		str++;
	}
	next = NULL;
	return (token);
}

/**
 * _strncmp - compare two strings
 * @s1: first string
 * @s2: second string
 * @n: number of characters to compare
 * Return: 0 if strings are equal, otherwise difference between first
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; i < n && s1[i] == s2[i]; i++)
		if (s1[i] == '\0')
			return (0);
	if (i == n)
		return (0);

	return (s1[i] - s2[i]);
}
