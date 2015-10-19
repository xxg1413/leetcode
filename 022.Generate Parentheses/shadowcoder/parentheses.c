/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "head.h"
void fun(int left, int right, char *line, int lp, char **result, int *returnSize)
{
	if (left == 0) {
		while (right--)
			line[lp++] = ')';
		memcpy(result[(*returnSize)++], line, lp);
		return ;
	}

	if (left == right) {
		line[lp++] = '(';
		return fun(left - 1, right, line, lp, result, returnSize);
	}

	line[lp++] = '(';
	fun(left - 1, right, line, lp, result, returnSize);
	line[lp - 1] = ')';
	fun(left, right - 1, line, lp, result, returnSize);
}

char** generateParenthesis(int n, int* returnSize) 
{
	int left = n, right = n;
	char line[1024] = {0};
	int lp = 0;
	char **result = (char **)calloc(sizeof(char *), 81920);
	int i;
	for (i = 0; i < 81920; i++) 
		result[i] = (char *)calloc(sizeof(char), n + 1);
	*returnSize = 0;
	fun(left, right, line, lp, result, returnSize);
	return result;
}

int main(int argc, char *argv[])
{
	int size = 0;
	char **ret = generateParenthesis(5, &size);


int dbg;
	for (dbg = 1; dbg < 11; dbg++) {
		ret = generateParenthesis(dbg, &size);
		printf("dbg = %d, size = %d\n", dbg, size);
	}

	int i;
	for (i = 0;i < size; i++) {
		;//printf("%s\n", ret[i]);
	}
	return 0;
}
