#include "head.h"

int fun(char *s) 
{
	int max = 0;
	int sp = -1;
	while (*s) {
		if (*s == '(') ++sp;
		else {
			if (sp >= 0) {
				sp--, max += 2;
				if (sp < 0) break;
			} else {
				max = 0;
				break;
			}
		}
		s++;
	}
	return sp >= 0? 0 : max;
}

int longestValidParentheses(char* s) 
{
	int max = 0;
	int cur = 0;
	int sum = 0;
	while (*s) {
		while (cur = fun(s)) {
			sum += cur;
			s += cur;
		}
		if (sum > max) max = sum;
		if (!*s) break;
		s += 1;
		sum = 0;
	}
	return max;
}

int main(int argc, char *argv[])
{
	printf("%d\n", longestValidParentheses("()(()"));
	printf("%d\n", longestValidParentheses("(()))))(((((((()))))))))()()()()()()()()()()()())()"));
	return 0;
}
