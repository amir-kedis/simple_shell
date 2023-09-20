

#include"hsh.h"
/**
 * addAlias - Adds an alias to the list.
 * @aliasList: Pointer to the AliasList structure.
 * @name: The alias name.
 * @command: The alias command.
 * Return: integer to detect failure.
 */
int addAlias(AliasList *aliasList, char *name, char *command)
{
	Alias *newAlias;
	int i;
	size_t size;

	if (!aliasList)
		initAliasList(&aliasList);

	for (i = 0; i < aliasList->count; i++)
	{
		if (_strcmp(aliasList->aliases[i].name, name) == 0)
		{
			aliasList->aliases[i].command = _strdup(command);
			return (1);
		}
		else if (_strcmp(aliasList->aliases[i].name, command) == 0)
			command = aliasList->aliases[i].command;
	}
	aliasList->count++;
	size = sizeof(Alias) * aliasList->count;
	aliasList->aliases = realloc(aliasList->aliases, size);
	if (!aliasList->aliases)
	{
		perror("Memory allocation error");
		return (-1);
	}
	newAlias = &(aliasList->aliases[aliasList->count - 1]);
	if (name && command)
	{
		newAlias->name = _strdup(name);
		newAlias->command = _strdup(command);
	}
	else
		return (-1);
	return (1);
}
/**
 * cleanupAliases - Frees memory allocated for aliases.
 * @aliasList: Pointer to the AliasList structure.
 */
void cleanupAliases(AliasList *aliasList)
{
	int i;

	for (i = 0; i < aliasList->count; i++)
	{
		free(aliasList->aliases[i].name);
		free(aliasList->aliases[i].command);
	}
	free(aliasList->aliases);
}
/**
* printalias - Print all aliases from an AliasList.
* @aliaslist: Pointer to the AliasList containing aliases.
*
* This function prints all aliases stored in the provided AliasList @aliaslist.
* It displays each alias's name and corresponding command.
*/
void printalias(AliasList *aliaslist)
{
	int i;

	if (aliaslist)
	{
		for (i = 0; i < aliaslist->count; i++)
		{
			_puts(aliaslist->aliases[i].name);
			_puts("='");
			_puts(aliaslist->aliases[i].command);
			_puts("'\n");
		}
	}
}
/**
* printaliasesbyname - Print aliases by name.
* @aliaslist: AliasList containing aliases.
* @name: The name of the aliases to print.
*/
void printaliasesbyname(AliasList *aliaslist, char *name)
{
	int i;

	for (i = 0; i < aliaslist->count; i++)
	{
		if (_strcmp(aliaslist->aliases[i].name, name) == 0)
		{
			_puts(aliaslist->aliases[i].name);
			_puts("='");
			_puts(aliaslist->aliases[i].command);
			_puts("'\n");
		}
	}
}
/**
* myalias - Display or set shell aliases.
* @env: Pointer to the shell's environment.
*
* This function allows users to manage shell aliases. It can display
* existing aliases or set new ones. Returns 1 on success, -1 on failure.
* Return: integer on failure 0
*/
int myalias(env_t *env)
{
	int i;
	char *p;

	if (!env->token_arr[1])
	{
		printalias(env->aliaslist);
		return (0);
	}
	else
	{
		for (i = 1; env->token_arr[i]; i++)
		{
			p = _strchr(env->token_arr[i], '=');
			if (p)
			{
				*p = '\0';
				addAlias(env->aliaslist, env->token_arr[i], p + 1);
			}
			else
				printaliasesbyname(env->aliaslist, env->token_arr[i]);
		}
	}
	return (0);
}
