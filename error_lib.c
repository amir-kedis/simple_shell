#include "hsh.h"
#include <unistd.h>

/**
 * exit_error - prints an error message and exits with a code
 * @file_name: name of file
 * @line_number: line number
 * @msg: message to print
 * @exit_code: exit code
 * Return: void
 */
void exit_error(char *file_name, int line_number, char *exc, char *msg, int exit_code, char *msgarg)
{
	_puts_fd(file_name, STDERR_FILENO);
	_puts_fd(": ", STDERR_FILENO);
	_putchar_fd(line_number + '0', STDERR_FILENO);
	_puts_fd(": ", STDERR_FILENO);
	_puts_fd(exc, STDERR_FILENO);
	_puts_fd(": ", STDERR_FILENO);
	_puts_fd(msg, STDERR_FILENO);
	if (msgarg)
	{
		_puts_fd(": ", STDERR_FILENO);
		_puts_fd(msgarg, STDERR_FILENO);
	}
	_puts_fd("\n", STDERR_FILENO); 
	exit(exit_code);
}
