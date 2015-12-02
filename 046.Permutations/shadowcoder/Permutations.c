#include "head.h"
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int *glonums = NULL;
static int gloncnt;
void fun(int *nums, int nsize, int **out, int *ocnt)
{
	if (!nsize) {
		memcpy(out[(*ocnt)++], glonums, sizeof(int) * gloncnt);
		return;
	}
	int i, tmp;
	for (i = 0; i < nsize; i++) {
		tmp = nums[0];
		nums[0] = nums[i];
		nums[i] = tmp;
		fun(nums + 1, nsize - 1, out, ocnt);
		tmp = nums[0];
		nums[0] = nums[i];
		nums[i] = tmp;
	}
}
int** permute(int* nums, int numsSize, int* returnSize) 
{
	int i = numsSize;
	int **out;
	int ocnt = 0;
	glonums = nums;
	gloncnt = numsSize;
	*returnSize = 1;
	while (i > 0) 
		*returnSize *= i--;
	out = (int **)malloc(sizeof(int *) * (*returnSize));
	for (i = 0; i < *returnSize; i++) 
		out[i] = (int *)malloc(sizeof(int) * numsSize);
	fun(nums, numsSize, out, &ocnt);

	return out;
}

int main(int argc, char *argv[])
{
	int nums[] = {1, 2, 3};
	int size = sizeof(nums) / 4;
	int ocnt = 0;
	int **ret = permute(nums, size, &ocnt);

	int i, j;
	for (i = 0; i < ocnt; i++) {
		for (j = 0; j < gloncnt; j++)
			printf("%d ", ret[i][j]);
		printf("\n");
	}
	return 0;
}
