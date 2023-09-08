#include "../list.h" /* Include the header file for your linked list functions */
#include <stdio.h>
#include <stdlib.h>

/* Declarations */

list_t *head = NULL; /* Initialize an empty linked list */

/* Function prototypes */

void test_list_push();
void test_list_print();
void test_list_pop();
void test_list_free();
void test_list_get_node();
void test_list_to_array();

int main()
{
	test_list_push();
	test_list_print();
	test_list_pop();
	test_list_free();
	test_list_get_node();
	test_list_to_array();

	return 0;
}

/* Function definitions */

void test_list_push()
{
	printf("Testing list_push function:\n");
	list_push(&head, "First");
	list_push(&head, "Second");
	list_push(&head, "Third");
	list_push(&head, "Fourth");
	list_push(&head, "Fifth");
}

void test_list_print()
{
	printf("\nTesting list_print function:\n");
	list_print(head);
}

void test_list_pop()
{
	list_t *popped;

	printf("\nTesting list_pop function:\n");
	popped = list_pop(&head);
	printf("Popped: %s\n", popped->str);
	free(popped); /* Don't forget to free the memory */
}

void test_list_free()
{
	printf("\nTesting list_free function:\n");
	list_free(&head);
}

void test_list_get_node()
{
	list_t *node;

	printf("\nTesting list_get_node function:\n");
	list_push(&head, "A");
	list_push(&head, "B");
	list_push(&head, "C");
	node = list_get_node(head, 1);
	if (node)
		printf("Node at index 1: %s\n", node->str);
	else
		printf("Node not found at index 1\n");
}

void test_list_to_array()
{
	char **array;
	int i;

	printf("\nTesting list_to_array function:\n");
	array = list_to_array(head);
	for (i = 0; array[i] != NULL; i++)
	{
		printf("Array[%d]: %s\n", i, array[i]);
		free(array[i]); /* Free each element of the array */
	}
	free(array); /* Free the array itself */
}

/* Output
Testing list_push function:
Testing list_print function:
First
Second
Third
Fourth
Fifth

Testing list_pop function:
Popped: Fifth

Testing list_free function:

Testing list_get_node function:
Node at index 1: B

Testing list_to_array function:
Array[0]: A
Array[1]: B
Array[2]: C
*/
