
#include "hsh.h"

/**
* _getenvvar - Retrieve the value of an environment variable
* @env: Pointer to the environment structure
* @name: Name of the variable to retrieve
* Return: Pointer to the variable's value or NULL if not found
*/
char *_getenvvar(env_t *env, char *name)
{
	char *found;
	list_t *node = env->env_list;

	while (node)
	{
		found = starts_with(node->str, name);
		if (found && *found)
			return (found);
		node = node->next;
	}
	return (NULL);
}
/**
* _getenvvarnode - Retrieve the value of an environment variable
* @env: Pointer to the environment structure
* @name: Name of the variable to retrieve
* Return: Pointer to the variable's value or NULL if not found
*/
list_t *_getenvvarnode(env_t *env, char *name)
{
	char *found;
	list_t *node = env->env_list;

	while (node)
	{
		found = starts_with(node->str, name);
		if (found && *found)
			return (node);
		node = node->next;
	}
	return (NULL);
}
/**
 * _setenvvar - Set or update an environment variable
 * @env: Pointer to the environment structure
 * @name: Name of the environment variable
 * @val: Value to set/update
 * Return: 1 on success, -1 on failure
 */
int _setenvvar(env_t *env, char *name, char *val)
{
	list_t *node;
	char *newstr;

	node = _getenvvarnode(env, name);
	if (!node)
		return (-1);
	newstr = malloc(_strlen(name) + _strlen(val) + 2);
	if (!newstr)
		return (-1);
	_strcpy(name, newstr);
	_strcat(newstr, val);
	free(node->str);
	node->str = newstr;
	return (1);
}
