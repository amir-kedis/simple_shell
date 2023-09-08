#include "hsh.h"

/**
 * hsh - Main shell loop function
 * Return: void
 */
void hsh(void)
{
	/* TODO: implement and adjust prototype as appropriate */
	char *line;
	size_t len = 0;
	ssize_t read_count;

	do
	{
		_puts(PROMPT);
		read_count = getline(&line, &len, stdin);
		_puts(line);
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
