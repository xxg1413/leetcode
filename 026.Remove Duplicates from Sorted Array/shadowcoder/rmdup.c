int removeDuplicates(int* nums, int numsSize) 
{
	int k = 1, i;
	if (numsSize < 2) return numsSize;
	for (i = 1; i < numsSize; i++) {
		if (nums[i] != nums[k-1])
			nums[k++] = nums[i];
	}
	return k;
}
