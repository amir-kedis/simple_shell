#include "hsh.h"
#include "list.h"

/**
 * hsh - Main shell loop function
 * @env: environment variables
 * Return: void
 */
void hsh(env_t *env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_count;
	char *word;
	list_t *tokens = NULL;
	char **tokens_array = NULL;

	/* clang-format off */
	do {
		/* clang-format on */
		if (isatty(STDIN_FILENO))
			_puts(PROMPT);
		read_count = custom_getline(&line, &len, stdin);
		if (read_count != -1)
		{
			word = _strtok(line, DILIM);
			while (word != NULL)
			{
				list_push(&tokens, word);
				word = _strtok(NULL, DILIM);
			}
			tokens_array = list_to_array(tokens);
			env->token_arr = tokens_array;
			execute_command(env);
			free_str_array(tokens_array);
			tokens_array = NULL;
			list_free(&tokens);
		}
	} while (read_count != -1);
	free(line);
}

#if !TEST_FILE_MODE

/**
 * main - entry point - temprorary driver function
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: EXIT_SUCCESS
 */

int main(int argc, char **argv, char **env)
{
	env_t _env = {NULL, NULL, NULL, -1, NULL, 0};

	_env.argv = argv;
	_env.env = env;
	_env.argc = argc;
	_env.env_list = array_to_list(env);

	hsh(&_env);
	list_free(&(_env.env_list));
	return (EXIT_SUCCESS);
}

#endif /* if 0 */
