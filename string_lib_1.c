#include"hsh.h"
/**
* my_strcpy - Copy 'src' to 'dest', null-terminate 'dest'.
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
