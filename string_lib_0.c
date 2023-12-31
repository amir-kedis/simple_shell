#include "hsh.h"

/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of string
 */
unsigned int _strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str && *str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to duplicated string
 */
char *_strdup(char *str)
{
	int len, i;
	char *newstr;

	len = _strlen(str);
	if (len == 0)
		return (NULL);

	newstr = malloc(sizeof(char) * len + 1);
	if (!newstr)
		return (NULL);
	for (i = 0; i < len; i++)
		newstr[i] = str[i];
	newstr[i] = '\0';
	return (newstr);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to concatenated string
 */
char *_strcat(char *dest, char *src)
{
	char *cur = dest;

	while (cur && *cur != '\0')
		cur++;

	while (src && *src != '\0')
	{
		*cur = *src;
		cur++;
		src++;
	}

	*cur = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if strings are equal, otherwise difference between first
 * non-matching characters
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else if (*s1 == '\0')
		return (*s2 * -1);
	else if (*s2 == '\0')
		return (*s1);
	else
		return ((*s1) - (*s2));
}
