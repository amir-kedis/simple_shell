#ifndef LIST_H
#define LIST_H

/**
 * strcut list - linked list
 * @str: string (data)
 * @next: pointer to next node
 *
 * Description: linked list node structure
 */
typedef struct list
{
	char *str;
	struct list *next;
	/* NOTE: We might need to add and index or something later. */
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

#endif
