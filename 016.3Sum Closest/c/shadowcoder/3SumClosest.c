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
					return aim;
			break;
		}
		if (num[mid] > aim) right = mid - 1;
		else left = mid + 1;
	}
	while (right >= 0) {
		if (right == i1 || right == i2) right--;
		else break;
	}
	while (left < size) {
		if (left == i1 || left == i2) left++;
		else break;
	}
	if (right >= 0 && left < size) {
		return abs(num[left] - aim) > abs(num[right] - aim)? num[right] : num[left];
	} else if(right < 0) 
		return num[left];
	else 
		return num[right];
}

int threeSumClosest(int* nums, int numsSize, int target) 
{
	int close = INT_MAX / 2;
	int i, j, k = 0;
	qsort(nums, numsSize, sizeof(int), mycompar);
	
	for (i = 0; i < numsSize - 2; i ++) {
		while (i && i < numsSize - 2 && nums[i - 1] == nums[i]) i++;
		if (i == numsSize - 2) break;
		for (j = i + 1; j < numsSize - 1; j ++) {
			while (j-1 > i && j < numsSize - 1 && nums[j] == nums[j - 1]) j++;
			if (j == numsSize - 1) break;
			k = search(nums, numsSize, target - nums[i] - nums[j], i, j);
			k = nums[i] + nums[j] + k;
			if (abs(target - k) < abs(close - target)) close = k;
			if (close == target) return target;
		}
	}

	return close;
}
