#include "hsh.h"
#include "list.h"

/**
 * list_to_array - convert a list to an array of strings
 * @head: pointer to head of list
 * Return: pointer to array of strings
 */
char **list_to_array(list_t *head)
{
	char **str_array;
	int i, len;
	list_t *cur;

	cur = head;
	len = 0;
	while (cur != NULL)
	{
		len++;
		cur = cur->next;
	}

	str_array = malloc(sizeof(char *) * (len + 1));
	if (str_array == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		str_array[i] = strdup(head->str);
		if (str_array[i] == NULL)
		{
			for (i--; i >= 0; i--)
			{
				free(str_array[i]);
			}
			free(str_array);
			return (NULL);
		}
		head = head->next;
	}

	str_array[i] = NULL;
	return (str_array);
}

/**
 * array_to_list - convert an array of strings to a list
 * @array: array of strings
 * Return: pointer to head of list
 */
list_t *array_to_list(char **array)
{
	list_t *head;
	int i;

	head = NULL;
	for (i = 0; array[i] != NULL; i++)
	{
		list_push(&head, array[i]);
	}

	return (head);
}
