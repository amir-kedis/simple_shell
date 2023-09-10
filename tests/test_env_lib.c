/* ======================================================== */
/* ================= TEST ENVIRO FUNCTIONS ================ */
/* ======================================================== */
#include "../hsh.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	printf("Testing _getenv function:\n");
	printf("PATH: %s\n", _getenv("PATH", NULL));
	printf("HOME: %s\n", _getenv("HOME", NULL));
	printf("PWD: %s\n", _getenv("PWD", NULL));
	printf("============================\n");
	printf("PATH: %s\n", _getenv("PATH", env));
	printf("HOME: %s\n", _getenv("HOME", env));
	printf("PWD: %s\n", _getenv("PWD", env));

	return (EXIT_SUCCESS);
}
