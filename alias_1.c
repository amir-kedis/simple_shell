
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
