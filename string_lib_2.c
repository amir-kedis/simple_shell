#include"hsh.h"
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
