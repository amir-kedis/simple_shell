#include "hsh.h"
/**
 * _strcpy - Copy 'src' to 'dest', null-terminate 'dest'.
 * @ogdest: Destination string.
 * @src: Source string.
 * Return: Pointer to 'dest'.
 */
void _strcpy(char *src, char *ogdest)
{
	char *dest = ogdest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}
/**
* _strcpylen - Copy at most 'size' characters from 'src' to 'ogdest'.
* @src: Source string to copy from.
* @ogdest: Destination buffer to copy to.
* @size: Maximum number of characters to copy.
*/
void _strcpylen(char *src, char *ogdest, int size)
{
	char *dest;
	int counter;

	counter = 0;
	dest = ogdest;
	while(*src != '\0' && counter != size)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}
