#include "hsh.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	static char buffer[BUF_SIZE];
	static int position = 0;
	int written_bytes = 0;

	if (position == BUF_SIZE || c == BUF_FLUSH)
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
