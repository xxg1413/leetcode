int mycompar(const void *a, const void *b)
{
	int *x = (int *)a;
	int *y = (int *)b;
	if (*x > *y) return 1;
	return *x == *y? 0 : -1;
}

int search(int *num, int size, int aim, int i1, int i2, int i3)
{
	int left = 0, right = size - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (num[mid] == aim) {
			int x = mid, y = mid, i;
			while (y < size && num[y] == aim) y++;
			for (i = mid; i < y; i++)
				if (i != i1 && i != i2 && i != i3)
					return i;
			break;
		}
		if (num[mid] > aim) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) 
{
	int i, j, o, k = 0;
	int tmp;
	int **out = (int **)calloc(sizeof(int *), 1024);
	for (i = 0; i < 1024; i++)
		out[i] = (int *)calloc(sizeof(int), 4);
	qsort(nums, numsSize, sizeof(int), mycompar);
	
	for (i = 0; i < numsSize - 3; i ++) {
		while (i && nums[i - 1] == nums[i]) i++;
		for (j = i + 1; j < numsSize - 2; j ++) {
			while (j-1 > i && nums[j] == nums[j - 1]) j++;
			for (o = j + 1; o < numsSize - 1; o ++) {
				while (o-1 > j && nums[o] == nums[o - 1]) o++;
				if (o == numsSize - 1) break;
				tmp = target - nums[i] - nums[j] - nums[o];
				if (tmp < nums[o]) break;
				if (search(nums, numsSize, tmp, i, j, o) >= 0) {	
					out[k][0] = nums[i];
					out[k][1] = nums[j];
					out[k][2] = nums[o];
					out[k++][3] = tmp;
				}
			}
		}
	}
	*returnSize = k;
	return out;
}
