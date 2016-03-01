#include "head.h"

int domerge(int *nums, int *nsize)
{
	int kk = 0, k = *nsize, i;
	if (nums[0] < 0) kk++;
	for (i = kk+1; i <= k; i++) {
		if (nums[i] < 0) {
			if (i == k) break;
			if (nums[i] + nums[kk] >= 0 && nums[i] + nums[i + 1] >= 0) {
				nums[kk] += nums[i] + nums[i + 1];
				i++;	
			} else {
				nums[++kk] = nums[i];
			}
		} else {
			if (nums[kk] >= 0)
				nums[kk] += nums[i];
			else 
				nums[++kk] = nums[i];
		}
	}

	if (kk == *nsize) return 0;
	*nsize = kk;
	return 1;
}

int listmax(int *nums, int numsSize)
{
	if (numsSize < 1) return 0;
	if (numsSize == 1) return nums[0];
	if (nums[0] <= 0) return nums[0] + listmax(nums + 1, numsSize - 1);
	int nextgt0 = listmax(nums + 2, numsSize - 2);
	if (nums[1] + nextgt0 >= 0)
		return nums[0] + nums[1] + nextgt0;
	else
		return nums[0];
}
int maxSubArray(int *nums, int numsSize)
{
	int max = INT_MIN;
	int i, k = 0;
	if (!numsSize) return 0;
	/* merge +/- */
	for( i = 0 ; i < numsSize ; i++ ) {
		if (nums[i] > max) max = nums[i];
		if (!i || !nums[i]) continue;
		if (nums[i] >= 0) {
			if (nums[k] >= 0) nums[k] += nums[i];
			else nums[++k] = nums[i];
		} else {
			if (nums[k] > 0) nums[++k] = nums[i];
			else nums[k] += nums[i];
		}
	}
	if (k == 0) return nums[k] <= 0? max:nums[k];

	/* merge +a -b +c --> a+b>=0 && b+c>=0 */
	while (domerge(nums, &k))
		;
	max = INT_MIN;
	int left = 0, right = k, sum;
	while (left <= right) {
		if (nums[left] <= 0) {
			left++;
			continue;
		}
		sum = listmax(nums + left, k+1-left);
		if (sum > max) max = sum;
		left++;
	}
	return max;
}

int main(int argc, char *argv[])
{
	int nums[] = {-5,8,-5,1,1,-3,5,5,-3,-3,6,4,-7,-4,-8,0,-1,-6};
	int size = sizeof(nums) / 4;

	int ret = maxSubArray(nums, size);

	return printf("%d\n", ret);
}
