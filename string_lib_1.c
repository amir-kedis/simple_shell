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

/**
 * copy_str_array - copy a string array
 * @str_array: string array to copy
 * Return: pointer to copy
 */
char **copy_str_array(char **str_array)
{
	int i, len;
	char **copy;

	len = 0;
	while (str_array[len] != NULL)
		len++;

	copy = malloc(sizeof(char *) * (len + 1));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		copy[i] = malloc(sizeof(char) * (_strlen(str_array[i]) + 1));
		if (copy[i] == NULL)
		{
			free_str_array(copy);
			return (NULL);
		}
		_strcpy(str_array[i], copy[i]);
	}
	copy[i] = NULL;

	return (copy);
}

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
