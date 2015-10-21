#include "head.h"
int *findright(int *num, int numsize)
{
	int left = 0, right = numsize - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (num[mid] >= *num) left = mid + 1;
		else if(num[mid] < *num) right = mid - 1;
	}
	return num + left - 1;
}

int findmid(int *nums, int *x, int size, int target)
{
	int left = 0, right = size - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (x[mid] < target) left = mid + 1;
		else if(x[mid] > target) right = mid - 1;
		else break;
	}	
	return left > right? -1 : x - nums + mid;
}
int search(int* nums, int numsSize, int target) 
{
	int *left, *right, *move = nums;
	while (1) {
		left = move;
		right = findright(move, numsSize - (left - nums));
		if (*left > target) move = right + 1;
		else if (*right < target) move = right + 1;
		else {
			return findmid(nums, left, right - left + 1, target);
		}
		if (right - nums == numsSize - 1) return -1;
	}
}
int main(int argc, char *argv[])
{
	//int nums[] = {1};
	int nums[] = {4, 5, 6, 7, 0, 1, 2};
	printf("%d\n", search(nums, sizeof(nums) / 4, 0));
	return 0;
}
