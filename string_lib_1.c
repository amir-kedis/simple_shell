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
/**
* custom_atoi - Convert a string to an integer.
*
* @str: The input string to be converted.
*
* Return: The integer value parsed from the input string.
*/
int custom_atoi(const char *str)
{
	int result, sign;

	result = 0; 
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			result = (result * 10) + (*str - '0');
		else
			break;
		str++;
	}
	return (result * sign);
}
/**
* isnumerical - Check if a string is a valid numerical value.
*
* @str: The string to check.
* Return: true if it's a valid numerical value, false otherwise.
*/
int isnumerical(const char *str)
{
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (-1);
	}
	return (1);
}
