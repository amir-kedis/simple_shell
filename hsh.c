#include "hsh.h"
#include "list.h"

/**
 * hsh - Main shell loop function
 * @env: environment variables
 * Return: void
 */
void hsh(char **env)
{
	/* TODO: implement and adjust prototype as appropriate */
	/* this is an ecpermiental function */
	/* that prints the prompt and prints back the tokens that is gets */
	char *line;
	size_t len = 0;
	ssize_t read_count;
	char *word;
	list_t *tokens = NULL;
	char **tokens_array = NULL;

	/* clang-format off */
	do {
		/* clang-format on */
		/* FIXME: this condition is temprorary */
#if INTERACTIVE_MODE
		_puts(PROMPT);
#endif
		read_count = custom_getline(&line, &len, stdin);

		if (read_count != -1)
		{
			word = strtok(line, DILIM);
			while (word != NULL)
			{
				list_push(&tokens, word);
				word = strtok(NULL, DILIM);
			}
			tokens_array = list_to_array(tokens);
			execute_command(tokens_array, env);
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
	UNUSED(argc);
	UNUSED(argv);
	hsh(env);
	return (EXIT_SUCCESS);
}

#endif /* if 0 */
