int mycompar(const void *a, const void *b)
{
	int *x = (int *)a;
	int *y = (int *)b;
	if (*x > *y) return 1;
	return *x == *y? 0 : -1;
}

int search(int *num, int size, int aim, int i1, int i2)
{
	int left = 0, right = size - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (num[mid] == aim) {
			int x = mid, y = mid, i;
			while (x >= 0 && num[x] == aim) x--;
			while (y < size && num[y] == aim) y++;
			for (i = x + 1; i < y; i++)
				if (i != i1 && i != i2)
					return i;
			break;
		}
		if (num[mid] > aim) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int** threeSum(int* nums, int numsSize, int* returnSize) 
{
	int i, j, k = 0;
	int **out = (int **)calloc(sizeof(int *), 1024);
	for (i = 0; i < 1024; i++)
		out[i] = (int *)calloc(sizeof(int), 3);
	qsort(nums, numsSize, sizeof(int), mycompar);
	
	for (i = 0; nums[i] <= 0; i ++) {
		while (i && i < numsSize - 2 && nums[i - 1] == nums[i]) i++;
		if (i == numsSize - 2) break;
		for (j = i + 1; j < numsSize - 1; j ++) {
			while (j-1 > i && j < numsSize - 1 && nums[j] == nums[j - 1]) j++;
			if (j == numsSize - 1) break;
			if (-nums[i] - nums[j] < nums[j]) break;
			if (search(nums, numsSize, -nums[i] - nums[j], i, j) >= 0) {	
				out[k][0] = nums[i];
				out[k][1] = nums[j];
				out[k++][2] = -nums[i] - nums[j];
			}
		}
	}
	*returnSize = k;
	return out;
}
