#include "head.h"
int firstMissingPositive(int* nums, int numsSize) 
{
	char *mark = (char *)calloc(sizeof(char), numsSize + 1);
	int i;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] <= 0) continue;
		if (nums[i] > numsSize) continue;
		mark[nums[i]] = 1;
	}

	for (i = 1; i < numsSize + 1; i++) {
		if (mark[i] == 0) return i;
	}

	return i;
}

int main(int argc, char *argv[])
{
	int nums[] = {1};
	int numsSize = sizeof(nums) / 4;
	int ret = firstMissingPositive(nums, numsSize);
	printf("%d\n", ret);

	return 0;
}
