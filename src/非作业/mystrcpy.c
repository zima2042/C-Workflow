#include<stdio.h>
char* mystrcpy(char* s1, char* s2)
{
	char* start = s1;
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return start;
}

int main(void)
{
	char s1[] = "helloworld";
	char s2[] = "abc";
	mystrcpy(s1, s2);
	printf("%s\n", s1);
	return 0;
}