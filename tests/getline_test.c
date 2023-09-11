#include"../hsh.h"
int main()
{
	FILE *f;
	char *s;
	size_t size = 0;
	int reading = 1;
	(void)reading;
	f = fopen("testgetline.txt", "r+");
	if (!f)
	{
		printf("failed to open file\n");
		return (0);
	}
	while(reading)
	{
		reading = custom_getline(&s, &size, f);
		printf("%s this is line\n", s);
		fflush(stdout);
	}
	fclose(f);
	return (0);
}
		


