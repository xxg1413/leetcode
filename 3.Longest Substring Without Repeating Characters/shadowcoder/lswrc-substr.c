#include "head.h"

void setcurmax(char *s, int slen, int cur, char *allc, int *maxlen, int *his)
{
	int i;
	if (cur > 0) {
		allc[s[cur - 1]] = 0;
		*maxlen -= 1;
	}
	for (i = cur + *maxlen; i < slen; i++) {
		if (!allc[s[i]]) {
			allc[s[i]] = 1;
			*maxlen += 1;
		} else
			break;
	}

	if (*maxlen > *his) *his = *maxlen;
}
int lengthOfLongestSubstring(char* s) 
{
	char allc[256] = {0};
	int maxlen = 0;
	int i, his = 0;
	int slen = strlen(s);
	for (i = 0; slen - i > maxlen; i++) {
		setcurmax(s, slen, i, allc, &maxlen, &his);
	}
	return his;
}

int main(int argc, char *argv[])
{
	printf("%d\n", lengthOfLongestSubstring(argv[1]));
	//printf("%d\n", lengthOfLongestSubstring("nxaxxx"));
	return 0;
}
