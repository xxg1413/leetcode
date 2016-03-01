#include "head.h"
int lengthOfLastWord(char* s) 
{
	while(*s == ' ') s++;
	int slen = strlen(s);
	if (!s || !slen) return 0;

	char *last = s + slen - 1;
	while (last - s > 0 && *last == ' ') last--;
	if (last == s) return *last == ' '? 0:1;
	last[1] = '\0';
	char *lastspace = strrchr(s, ' ');
	if (!lastspace) return strlen(s);
	return strlen(lastspace + 1);
}

int main(int argc, char *argv[])
{
	char s[] = "   asddf...,   ";
	int ret = lengthOfLastWord(s);

	printf("%d\n", ret);
	return 0;
}
