#include "head.h"

char *mystrstr(char *src, char *dst)
{
	int slen = strlen(src);
	int len = strlen(dst);
	char *a = src;
	char *b = dst;
	int cnt = 0, i;
	while (slen >= len) {
		b = dst;
		a = src + cnt;
		for (i = 0; i < len; i++) 
			if (a[i] != b[i] && b[i] != '?') break;
		if (i == len) return src + cnt;
		slen--;
		cnt++;
	}
	return NULL;
}

int dofun(char *s, char **pword, int pcnt, int begin, int end)
{
	if (pcnt < 1) return (begin || end || !*s)? 1:0;
	char *out = mystrstr(s, pword[0]);
	int pw0 = strlen(pword[0]);
	if (pcnt == 1) {
		if (!out) return 0;
		if (begin)
			return (end || mystrstr(s + strlen(s) - pw0, pword[0]))? 1:0;
		else 
			return ((end && out == s) || (out == s && !out[pw0]))? 1:0;
	}
	char *ss = s;
	int cur = 0;
	if (!begin) {
		if (out != s) return 0;
		cur ++;
		ss += pw0;
	}
	
	if (!end) {
		int sslen = strlen(ss);
		int plen = strlen(pword[pcnt - 1]);
		if (sslen < plen) return 0;
		if (!mystrstr(ss + sslen - plen, pword[pcnt - 1]))
			return 0;
		char *t = s + strlen(s) - plen;
		*t = '\0';
		pcnt--;
	}
	for (; cur < pcnt; cur++) {
		out = mystrstr(ss, pword[cur]);
		int plen = strlen(pword[cur]);
		if (!out) return 0;
		ss = out + plen;
	}
	return 1;
}

int isMatch(char* s, char* p) 
{
	int i, ret, begin, end, wcnt = 0;
	char *pword[2048] = {0};
	char *pw;

	/* split string by char '*' */
	begin = end = 0;
	if (*p == '*') begin = 1;
	if (p[strlen(p) - 1] == '*') end = 1;
	pw = strtok(p, "*");
	while (pw) {
		int pwlen = strlen(pw);
		pword[wcnt] = (char *)malloc(sizeof(char) * (pwlen + 1));
		memcpy(pword[wcnt++], pw, pwlen + 1);
		pw = strtok(NULL, "*");	
	}

	ret = dofun(s, pword, wcnt, begin, end);

	for (i = 0; i < wcnt; i++) free(pword[i]);

	return ret;
}

int main(int argc, char *argv[])
{
	char s[] = {"babaabbbbbaaaaabbaababbaaaaaaabbaabaabbbabbaabbbbb"};
	char p[] = {"*ba**bbbb"};
	printf("%d\n", isMatch(s, p));
}
