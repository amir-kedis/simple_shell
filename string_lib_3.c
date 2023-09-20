#include "hsh.h"
/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	/* clang-format off */
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

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
