#include"hsh.h"
/**
* free - Deallocates memory for an environment variable list.
* @env: Pointer to the environment variable list.
*/
void freeall(env_t *env)
{
	if (env->env_list)
		list_free(&env->env_list);
	if (env->token_arr)
		free_str_array(env->token_arr);
	if (env->aliaslist)
		cleanupAliases(env->aliaslist);
	free(env->aliaslist);
}

