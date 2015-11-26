#include "head.h"

void fun(char *nums, int nsize, int lev, char *out)
{
	if (!nsize) return;
	int total = 1;
	int i;
	for (i = 1; i <= nsize; i++) total *= i;
	int per = total / nsize;
	int po = (lev - 1) / per;
	*out++ = nums[po];
	for (i = po + 1; i < nsize; i++)
		nums[i - 1] = nums[i];
	nsize--;
	fun(nums, nsize, lev - per * po, out);
}
char* getPermutation(int n, int k) 
{
	char buf[10] = {0};
	char *ret = (char *)calloc(sizeof(char), 10);
	int i;
	for (i = 0; i < n; i++)
		buf[i] = '1' + i;
	fun(buf, n, k, ret);
	return ret;
}

int main(int argc, char *argv[])
{
	char *ret = getPermutation(5, 96);

	return printf("%s\n", ret);
}
