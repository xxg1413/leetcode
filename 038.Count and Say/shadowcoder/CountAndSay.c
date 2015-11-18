#include "head.h"

char* countAndSay(int n) 
{
	char *ret = (char *)calloc(sizeof(char), 8192);
	char *tmp = (char *)calloc(sizeof(char), 8192);
	char buff[8];
	ret[0] = '1';
	if (n == 1) return ret;
	n--;
	while (n--) {
		char *p = ret;
		char *move;
		char *pp = tmp;
		while (*p) {
			char say = p[0];
			int count = 0;
			move = p;
			while (move[count] == *p) {
				count++;
			}
			snprintf(buff, 8, "%d%c", count, say);
			strcat(tmp, buff);
			p += count;
		}
		memcpy(ret, tmp, strlen(tmp));
		tmp[0] = 0;
	}
	free(tmp);
	return ret;
}

int main(int argc, char *argv[])
{
	char *ret = countAndSay(30);
	printf("%s\n", ret);
	return 0;
}
