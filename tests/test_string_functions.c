/* ======================================================== */
/* ================= TEST STRING FUNCTIONS ================ */
/* ======================================================== */
#include "../hsh.h"
#include <stdio.h>
#include <string.h>

unsigned int _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void _strcpy(char *src, char *dest);

int main()
{
	unsigned int len1, len2, len3;
	int cmp1, cmp2, cmp3;
	char str1[] = "";							 /* Empty string */
	char str2[] = "Hello, World!"; /* Regular string */
	char str3[1000];							 /* Long string */
	char src[] = "Hello";
	char *dup;
	char src2[] = ""; /* Empty string */
	char *dup2;
	char dest[100] = "Hello";
	char src3[] = ", World!";
	char dest2[100] = ""; /* Empty string */
	char src4[] = "Hello, World!";
	char s1[] = "abc";
	char s2[] = "abc";
	char s3[] = "abc";
	char s4[] = "def";
	char s5[] = "def";
	char s6[] = "abc";
	char src5[] = "Hello";
	char dest3[10];
	char src6[] = ""; /* Empty string */
	char dest4[10];

	len1 = _strlen(str1);
	len2 = _strlen(str2);
	len3 = _strlen(str3);
	printf("Length of str1: %u\n", len1);
	printf("Length of str2: %u\n", len2);
	printf("Length of str3: %u\n", len3);

	dup = _strdup(src);
	printf("Duplicated string: %s\n", dup);
	free(dup);

	dup2 = _strdup(src2);
	printf("Duplicated string: %s\n", dup2);
	free(dup2);

	_strcat(dest, src3);
	printf("Concatenated string: %s\n", dest);

	_strcat(dest2, src4);
	printf("Concatenated string: %s\n", dest2);

	cmp1 = _strcmp(s1, s2);
	cmp2 = _strcmp(s3, s4);
	cmp3 = _strcmp(s5, s6);
	printf("Comparison result: %d\n", cmp1);
	printf("Comparison result: %d\n", cmp2);
	printf("Comparison result: %d\n", cmp3);

	_strcpy(src5, dest3);
	printf("Copied string: %s\n", dest3);

	_strcpy(src6, dest4);
	printf("Copied string: %s\n", dest4);

	return 0;
}
