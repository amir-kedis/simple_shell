#include "hsh.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	static char buffer[BUF_SIZE];
	static int position;
	int written_bytes = 0;

	if (position >= BUF_SIZE || c == BUF_FLUSH)
	{
		written_bytes = write(STDOUT_FILENO, buffer, position);
		position = 0;
	}

	if (c != BUF_FLUSH)
	{
		buffer[position] = c;
		position++;
	}

	return (written_bytes == -1 ? -1 : 1);
}

/**
 * _putchar_fd - writes the character c to the specified file descriptor
 * @c: The character to print
 * @fd: The file descriptor
 * Return: On success 1.
 */
int _putchar_fd(char c, int fd)
{
	static char buffer[BUF_SIZE];
	static int position;
	int written_bytes = 0;

	if (position >= BUF_SIZE || c == BUF_FLUSH)
	{
		written_bytes = write(fd, buffer, position);
		position = 0;
	}

	if (c != BUF_FLUSH)
	{
		buffer[position] = c;
		position++;
	}

	return (written_bytes == -1 ? -1 : 1);
}

/**
 * _puts - prints a string to stdout
 * @str: string to print
 * Return: number of characters printed
 */
int _puts(char *str)
{
	int chars_printed = 0;

	while (*str)
	{
		_putchar(*str);
		str++;
		chars_printed++;
	}

	_putchar(BUF_FLUSH);
	return (chars_printed);
}

/**
 * _puts_fd - prints a string to the specified file descriptor
 * @str: string to print
 * @fd: file descriptor
 * Return: number of characters printed
 */
int _puts_fd(char *str, int fd)
{
	int chars_printed = 0;

	while (*str)
	{
		_putchar_fd(*str, fd);
		str++;
		chars_printed++;
	}

	_putchar_fd(BUF_FLUSH, fd);
	return (chars_printed);
}
