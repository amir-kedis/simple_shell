#include "hsh.h"
#include <unistd.h>

/**
 * exit_error - prints an error message and exits with a code
 * @f_: name of file
 * @l_: line number
 * @exc: executable name
 * @msg: message to print
 * @exit_: exit code
 * @msga: msg for error
 * @env: environment
 * Return: void
 */
void exit_error(char *f_, int l_, char *exc, char *msg, int exit_, char *msga,
								env_t *env)
{
	/* FIXME: needs to be refacterd into printing error and seting exit status */
	_puts_fd(f_, STDERR_FILENO);
	_puts_fd(": ", STDERR_FILENO);
	_putchar_fd(l_ + '0', STDERR_FILENO);
	_puts_fd(": ", STDERR_FILENO);
	_puts_fd(exc, STDERR_FILENO);
	_puts_fd(": ", STDERR_FILENO);
	_puts_fd(msg, STDERR_FILENO);
	if (msga)
	{
		_puts_fd(": ", STDERR_FILENO);
		_puts_fd(msga, STDERR_FILENO);
	}
	_puts_fd("\n", STDERR_FILENO);
	env->last_exit_status = exit_;
	/* exit(exit_); */
}
