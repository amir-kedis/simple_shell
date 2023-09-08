#include "hsh.h"
#include "list.h"

/**
 * list_push - add a node to the end of a list
 * @head: pointer to head of list
 * @str: string to be added to list
 * Return: pointer to new node
 */
list_t *list_push(list_t **head, char *str)
{
	list_t *node_to_add = malloc(sizeof(list_t));

	if (node_to_add == NULL)
	{
		return (NULL);
	}

	node_to_add->str = strdup(str);
	node_to_add->length = strlen(str);
	node_to_add->next = NULL;
	if (node_to_add->str == NULL)
	{
		return (NULL);
	}

	if (*head == NULL)
	{
		*head = node_to_add;
	}
	else
	{
		list_t *last_node = *head;

		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = node_to_add;
	}

	return (node_to_add);
}

/**
 * list_print - print a list
 * @head: pointer to head of list
 */
void list_print(list_t *head)
{
	list_t *cur = head;

	while (cur != NULL)
	{
		_puts(cur->str);
		_puts("\n");
		cur = cur->next;
	}
}

/**
 * list_pop - remove a node from the end of a list
 * @head:  pointer to head of list
 * Return: pointer to node removed
 */
list_t *list_pop(list_t **head)
{
	list_t *cur = *head;
	list_t *prev = NULL;

	if (cur == NULL)
	{
		return (NULL);
	}

	while (cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
	}

	if (prev == NULL)
	{
		*head = NULL;
	}
	else
	{
		prev->next = NULL;
	}

	return (cur);
}

/**
 * list_free - free a list
 * @head: pointer to head of list
 */
void list_free(list_t **head)
{
	list_t *cur = *head;
	list_t *next;

	while (cur != NULL)
	{
		next = cur->next;
		free(cur->str);
		free(cur);
		cur = next;
	}

	*head = NULL;
}

/**
 * list_get_node - get a node at a specific index
 * @head: pointer to head of list
 * @index: index of node to retrieve
 * Return: pointer to node at index
 */

list_t *list_get_node(list_t *head, unsigned int index)
{
	unsigned int i = 0;
	list_t *cur = head;

	while (cur != NULL && i < index)
	{
		cur = cur->next;
		i++;
	}

	return (cur);
}
