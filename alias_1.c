
#include"hsh.h"

/**
 * initAliasList - Initializes an alias list.
 * @aliasList: Pointer to the AliasList structure to initialize.
 */
void initAliasList(AliasList **aliasList)
{
	*aliasList = malloc(sizeof(AliasList));
	if (!*aliasList)
		return;
	(*aliasList)->aliases = NULL;
	(*aliasList)->count = 0;
}
/**
* excualias - Execute a command or expand an alias.
* @env: Pointer to the shell's environment.
* @cmd: Command to execute or alias to expand.
* Return: Expanded command or NULL on failure.
*/
char *excualias(env_t *env, char *cmd)
{
	int i;
	AliasList *al;

	al = env->aliaslist;
	if (al)
	{
		for (i = 0; i < al->count; i++)
		{
			if (_strcmp(al->aliases[i].name, cmd) == 0)
			{
				return (al->aliases[i].command);
			}
		}
	}
	return (NULL);
}
