#include "head.h"
char* longestCommonPrefix(char** strs, int strsSize) 
{
	if (!strsSize) return "";
	static char out[1024];int outlen;
	snprintf(out, 1024, "%s", strs[0]);
	outlen = strlen(out);
	int cnt = strsSize - 1;
	while (cnt) {
		if (strncmp(out, strs[cnt], outlen)) {
			char *a = out, *b = strs[cnt];
			while (*a == *b) {
				a++;
				b++;
			}
			*a = 0;
			outlen = strlen(out);
		}
		cnt --;
	}
	return out;
}

int main(int argc, char *argv[])
{
	char *s[] = {
		"asdfaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"asdfbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
		"asdfccccccccccccccccccccccccccccccccccccccccccccc",
		"asdfddddddddddddddddddddddddddddddddddddddddd",
		"asdfeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
		"asdfaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	};
	char *p = longestCommonPrefix(s, 6);
	printf("%s\n", p);
	return 0;
}
