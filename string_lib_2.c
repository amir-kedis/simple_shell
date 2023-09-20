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

/**
 * _str_to_word_array - splits a string into words
 * @str: string to split
 * @delim: delimiters
 * Return: pointer to array of words
 */
char **_str_to_word_array(char *str, char *delim)
{
	char **array = NULL;
	char *token;
	int i = 0;

	token = _strtok(str, delim);
	while (token != NULL)
	{
		array = _realloc(array, i * sizeof(char *), (i + 1) * sizeof(char *));
		array[i] = _strdup(token);
		token = _strtok(NULL, delim);
		i++;
	}
	array = _realloc(array, i * sizeof(char *), (i + 1) * sizeof(char *));
	array[i] = NULL;

	return (array);
/**
 *starts_with - finds if string starts with starting
 * @string: big string
 * @starting: string to find
 * Return: the last char of string or NULL
 */
char *starts_with(const char *string, const char *starting)
{
	while (*starting)
	{
		if (*starting++ != *string++)
			return (NULL);
	}
	return ((char *)string);
}
