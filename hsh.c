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

	printf("%s", PROMPT);
	getline(&line, &len, stdin);
	printf("%s", line);

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
