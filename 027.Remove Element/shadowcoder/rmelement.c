int removeElement(int* nums, int numsSize, int val) 
{
	int k = 0, i;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] != val) nums[k++] = nums[i];
	}
	return k;
}
