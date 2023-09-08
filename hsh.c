#include "hsh.h"

/**
 * hsh - Main shell loop function
 * Return: void
 */
void hsh(void)
{
	/* TODO: implement and adjust prototype as appropriate */
	/* this is an ecpermiental function */
	/* that prints the prompt and prints back the tokens that is gets */
	char *line;
	size_t len = 0;
	ssize_t read_count;
	char *word;

	do
	{
		_puts(PROMPT);
		read_count = getline(&line, &len, stdin);

		if (read_count != -1)
		{
			word = strtok(line, DILIM);
			while (word != NULL)
			{
				_puts(word);
				_puts("\n");
				word = strtok(NULL, DILIM);
			}
		}
	}
	while (read_count != -1);

	free(line);
	return;
}

/**
 * main - entry point - temprorary driver function
 * Return: EXIT_SUCCESS
 */

int main(void)
{
	hsh();	
	return (EXIT_SUCCESS);
}
