#include "hsh.h"
#include "list.h"

/**
 * hsh - main function for shell
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
	char **tokens_array = NULL, **commands = NULL;
	int i;

	/* clang-format off */
	do {
		if (isatty(STDIN_FILENO))
			_puts(PROMPT);
		read_count = custom_getline(&line, &len, stdin);
		if (read_count == -1)
			break;
		remove_comments(line);
		commands = _str_to_word_array(line, ";");
		i = 0;
		while (commands[i])
		{
			tokens = NULL;
			word = _strtok(commands[i++], DILIM);
			while (word != NULL)
			{
				list_push(&tokens, word);
				word = _strtok(NULL, DILIM);
			}
			tokens_array = list_to_array(tokens);
			env->token_arr = tokens_array;
			list_free(&tokens);
			free(line);
			line = NULL;
			env->commands = commands;
			execute_command(env);
			free_str_array(tokens_array);
			tokens_array = NULL; }
		free_str_array(commands);
	} while (read_count != -1);
	if (line != NULL)
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
	env_t _env = {NULL, NULL, NULL, -1, NULL, 0, 0, NULL, NULL};

	_env.argv = argv;
	_env.env = env;
	_env.argc = argc;
	_env.env_list = array_to_list(env);

	hsh(&_env);
	list_free(&(_env.env_list));
	exit(_env.last_exit_status);
	return (EXIT_SUCCESS);
}

#endif /* if 0 */
