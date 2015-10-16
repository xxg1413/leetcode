#include "head.h"
int romanToInt(char* s) 
{
	int ret = 0;
	int alpha[26] = {0};
	alpha['I' - 'A'] = 1;
	alpha['V' - 'A'] = 5;
	alpha['X' - 'A'] = 10;
	alpha['L' - 'A'] = 50;
	alpha['C' - 'A'] = 100;
	alpha['D' - 'A'] = 500;
	alpha['M' - 'A'] = 1000;
	while (*s && *s == 'M') {
		ret += 1000;
		s++;
	}
	while (*s && s[1]) {
		if (alpha[s[0] - 'A'] < alpha[s[1] - 'A']) {
			ret += alpha[s[1] - 'A'] - alpha[s[0] - 'A'];
			s += 2;
		} else {
			ret += alpha[s[0] - 'A'];
			s ++;
		}
	}
	if (*s) ret += alpha[s[0] - 'A'];
	return ret;
}

int main(int argc, char *argv[])
{
	return printf("%d\n", romanToInt(argv[1]));
}
