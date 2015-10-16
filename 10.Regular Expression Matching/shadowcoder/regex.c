#include "head.h"
char *nextlogiceq(char s, char *p)
{
	if (!*p) return NULL;
	if (*p == '.' || s == *p) return p;
	if (p[1] == '*') return nextlogiceq(s, p + 2);
	return NULL;
}

int isMatch(char* s, char* p) 
{
	while (*p && *s) {
		if (p[1] != '*') {
			if (*p == '.' || *s == *p) 
				p++,s++;
			else
				return 0;
		} else {
			if (*p != '.' && *s != *p) {
			    p += 2;
			    continue;
			}
			char *tmp = nextlogiceq(*s, p + 2);
			if (tmp)
				if (isMatch(s, tmp)) return  1;
			s += 1;
			continue;
		}
	}

	if (*s) return 0;
	while (*p)
		if (p[1] == '*') p+=2;
		else return 0;
	return 1;
}

int main(int argc, char *argv[])
{
	char s[] = {"bbab"};
	char p[] = {"b*a*"};
	printf("%d\n", isMatch(s, p));
}
