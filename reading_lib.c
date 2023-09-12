
#include"hsh.h"
/**
* custom_getchar - Read a character from FILE stream @f.
* @f: FILE pointer to the input stream.
*
* Return: The character read as an integer, or EOF on error or end of file.
*/
int custom_getchar(FILE *f)
{
	char reado;
	int numread, fd;

	fd = fileno(f);
	if (fd == -1)
	{
		perror("Failed to get file descriptor");
		return (EOF);
	}
	else
	{
		numread = read(fd, &reado, 1);
		if (numread == 1)
			return ((int)reado);
		perror("Failed to read");
		return (EOF);
	}
}
/**
* custom_getline - Read a line from FILE stream @f and store it in @line.
* @s: Pointer to the buffer.
* @startlen: Pointer to the initial buffer size.
* @f: FILE stream to read from.
* Return: Number of characters read, or -1 on error.
*/
size_t custom_getline(char **s, size_t *startlen, FILE *f)
{
	static char buffer[BUF_SIZE];
	static int bufferindex, buffersize;
	int numread, index = 0, fd;
	char *new;

	if (s == NULL || startlen == NULL || f == NULL) /*check if valid vars*/
		return (-1);
	fd = fileno(f);
	if (fd == -1)
		return (-1);
	if (*s == NULL)
	{	*s = malloc(BUF_SIZE * 2);
		if (*s == NULL)
			return (-1);
		*startlen = BUF_SIZE * 2; }
	bufferindex = 0;
	while (1)
	{
		if (bufferindex == 0 || bufferindex == buffersize)
		{	bufferindex = 0;
			numread = read(fd, buffer, sizeof(buffer));
			if (numread == -1)
			{	free(*s);
				return (-1); }
			if (numread == 0)
				break;
			buffersize = numread;
			if (!((*startlen - index - 1) > (size_t)numread + 1))
			{	new = realloc(*s, (*startlen) * 2 + numread);
				if (new == NULL)
				{	free(*s);
					return (-1); }
				*startlen *= 2;
				*s = new; } }
		while (buffer[bufferindex] != '\n' && bufferindex < buffersize)
			(*s)[index++] = buffer[bufferindex++];
		if (buffer[bufferindex++] == '\n')
			break; }
	(*s)[index] = '\0';
	return (index); }
