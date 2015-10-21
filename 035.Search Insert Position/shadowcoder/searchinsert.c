int searchInsert(int* nums, int numsSize, int target) 
{
	int left = 0, right = numsSize - 1, mid;
	while(left <= right) {
		mid = (left + right) / 2;
		if(nums[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	return left;
}
