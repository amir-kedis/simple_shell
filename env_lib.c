#include "hsh.h"

/**
* _getenv - Retrieve the value of an environment variable
* @env: Pointer to the environment structure
* @name: Name of the variable to retrieve
* Return: Pointer to the variable's value or NULL if not found
*/
char *_getenv(env_t *env, char *name)
{
	char *found;
	list_t *node = env->env_list;

	while (node)
	{
		found = _starts_with(node->str, name);
		if (found && *found)
			return (found);
		node = node->next;
	}
	return (NULL);
}

