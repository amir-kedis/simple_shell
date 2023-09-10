#include"../hsh.h"

int main()
{
	FILE *f;
	char *s;
	size_t size = 0;
	int reading = 1;
	f = fopen("testgetline.txt", "r+");
	if (!f)
	{
		printf("failed to open file\n");
		return (0);
	}
	while (reading >= 1)
	{
		reading = custom_getline(&s, &size, f);
		printf("%s\n", s);
	}
	fclose(f);
	return (0);
}
		


