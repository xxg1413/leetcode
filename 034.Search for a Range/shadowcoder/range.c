/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "head.h"
int find(int* nums, int numsSize, int target, int lr)
{
	int left = 0, right = numsSize - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (nums[mid] < target) left = mid + 1;
		else if (nums[mid] > target) right = mid - 1;
		else {
			if (lr == 0) right = mid - 1;
			else left = mid + 1;
		}
	}
	if (lr == 0 && nums[left] == target) return left;
	if (lr == 1 && nums[right] == target) return right;
	return -1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
	int *ret = (int *)malloc(sizeof(int) * 2);
	*returnSize = 2;
	int left = find(nums, numsSize, target, 0);
	if (left < 0) {
		ret[0] = ret[1] = -1;
		return ret;
	}
	int right = find(nums, numsSize, target, 1);
	if (right < 0) {
		ret[0] = ret[1] = -1;
		return ret;
	}
	ret[0] = left;
	ret[1] = right;
	return ret;
}

int main(int argc, char *argv[])
{
	//int nums[] = {1};int size;
	int nums[] = {5, 7, 7, 8, 8, 10};int size;
	int *p = searchRange(nums, sizeof(nums) / 4, 8, &size);
	printf("%d, %d\n", p[0], p[1]);
	return 0;
}
