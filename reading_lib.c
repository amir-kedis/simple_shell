#include"hsh.h"
#define BUFFER_SIZE 128
/**
* custom_getchar - Read a character from FILE stream @f.
* @f: FILE pointer to the input stream.
*
* Returns: The character read as an integer, or EOF on error or end of file.
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
		else
			{
				perror("Failed to read");
				return (EOF);
			}
	}
}
/**
* custom_getline - Read a line from FILE stream @f and store it in @line.
* @line: Pointer to the buffer.
* @startlen: Pointer to the initial buffer size.
* @f: FILE stream to read from.
* Return: Number of characters read (excluding null terminator), or -1 on error.
*/
size_t custom_getline(char **s, size_t *startlen, FILE *f)
{
	static char buffer[BUFFER_SIZE];
	static int bufferindex = 0, buffersize = 0;
	int fd;
	size_t sizeofstr = 0;
	int numread, index = 0;
	char *old, *new;

	if (s == NULL || startlen == NULL || f == NULL)
		return (-1);
	fd = fileno(f);
	if (*s == NULL)
	{
		*s = malloc(BUFFER_SIZE);
		if (*s == NULL)
		{
			perror("Failed to allocate memoryoo");
			return (-1);
		}
		*startlen = BUFFER_SIZE;
	}
	if(fd == -1)
	{
		perror("Failed to read from file");
		free(*s);
		return (-1);
	}
	while (1)
	{
		numread = read(fd, buffer, sizeof(buffer));
		if (numread == -1)
		{
			perror("Failed reading");
			free(*s);
			return (-1);
		}
		if (numread == 0)
		{
			break;
		}	
		if(!((*startlen - index - 1) > numread + 1))
		{
			old = *s;
			new = realloc(*s, (*startlen) * 2 + numread);
			if (new == NULL)
			{
				perror("Failed memory allocation");
				free(old);
				return (-1);
			}
			*startlen *= 2;
			*s = new;
		}
	_strcpylen(buffer, *s + index, numread);
	index += numread;
	(*s)[index] = '\0';
	}
}
