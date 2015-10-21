#include "head.h"

int divide(int dividend, int divisor) 
{
	if (dividend == INT_MIN) {
		if (divisor == -1 || divisor == 0) return INT_MAX;
		if (divisor == INT_MIN) return 1;
	}
	if (divisor == INT_MIN) return 0;

	int flag, remain = 0, result = 0, o = 1;

	if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) 
		o = -1;
	flag = divisor < 0? -divisor : divisor;
	if (dividend == INT_MIN) {
		dividend += flag;
		result += 1;
	}
	if (dividend < 0) dividend = -dividend;

	int i, f;
	while (dividend > 0) {
		f = 0;
		for (i = 0;dividend >= flag; i++) {
			f = (flag << i);
			if (f >= dividend || f < 0) break;
		}
		if (f > dividend || f < 0) i -= 1;
		result += 1 << i;
		dividend -= flag << i;
		if (dividend < 0) remain = 1;
	}

	if (remain) result -= 1;
	return o * result;
}

int main(int argc, char *argv[])
{
	printf("%d\n", divide(atoi(argv[1]), atoi(argv[2])));
	return 0;
}
