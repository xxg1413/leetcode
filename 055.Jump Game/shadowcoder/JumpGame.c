#include "head.h"

bool canJump(int *nums, int size)
{
	int right = 0;
	int i, j, r;
	if (size < 2) return 1;
	if (nums[0] >= size - 1) return 1;
	int l0 = 0, l1 = nums[0];
	if (l0 == l1) return 0;
	for (i = 2; i < size; i++) {
		int tr = -1;
		for (j = l1; j >= l0; j--) 
			if (j + nums[j] > tr) {
				tr = j + nums[j];
				if (tr >= size -1) break;
			}
		l0 = l1;
		l1 = tr;
		if (l1 >= size - 1) {
			i = 1;
			break;
		}
		if (l0 == l1) {
			i = 0;
			break;
		}
	}
		
	return i;
}

int main(int argc, char *argv[])
{
	int nums[] = {0,1};
	int size = sizeof(nums) / 4;
	int ret = jump(nums, size);

	return printf("%d\n", ret);
}
