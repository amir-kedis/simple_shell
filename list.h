#ifndef LIST_H
#define LIST_H

/**
 * struct list - singly linked list
 * @str: string - (data)
 * @length: length of the string
 * @next: points to the next node
 * Description: singly linked list node structure
 */
typedef struct list
{
	char *str;
	int length;
	struct list *next;
} list_t;

/* ===================================================== */
/* ===================== PROTOTYPES ==================== */
/* ===================================================== */
list_t *list_push(list_t **head, char *str);
void list_print(list_t *head);
list_t *list_pop(list_t **head);
void list_free(list_t **head);
list_t *list_get_node(list_t *head, unsigned int index);
char **list_to_array(list_t *head);
list_t *array_to_list(char **array);
list_t *list_find_node_starting_with(list_t *head, char *str);
int list_delete_node(list_t **head, list_t *node);

#endif
