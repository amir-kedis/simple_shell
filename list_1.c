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

/**
 * list_push - add a node to the end of a list
 * @head: pointer to head of list
 * @str: string to add to node
 * Return: pointer to new node
 */
list_t *list_find_node_starting_with(list_t *head, char *str)
{
	list_t *cur;

	cur = head;
	while (cur != NULL)
	{
		if (_strncmp(cur->str, str, _strlen(str)) == 0)
			return (cur);
		cur = cur->next;
	}

	return (NULL);
}

/**
 * list_delete_node - delete a node from a list
 * @head: pointer to head of list
 * @node: node to delete
 *  Return: 1 if success, 0 if failure
 */
int list_delete_node(list_t **head, list_t *node)
{
	list_t *cur;

	if (*head == NULL)
		return (0);

	if (*head == node)
	{
		*head = node->next;
		free(node->str);
		free(node);
		return (1);
	}

	cur = *head;
	while (cur->next != NULL)
	{
		if (cur->next == node)
		{
			cur->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		cur = cur->next;
	}

	return (0);
}
