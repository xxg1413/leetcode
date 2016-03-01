#include "head.h"

int findleft(int *height, int size, int loc)
{
	if (height[loc - 1] <= height[loc]) return -1;
	else return loc - 1;
}

int findright(int *height, int size, int loc)
{
	int i, right = -1;
	for (i = loc + 1; i < size; i++) {
		if ((height[i] > height[loc]))
			if (right < 0)
				right = i;
			else if (height[i] > height[right])
				right = i;
		if (height[right] >= height[loc - 1]) break;
	}
	return right;
}

int trap(int* height, int heightSize) 
{
	int i, j, left, right;
	int ret = 0;
	for (i = 1; i < heightSize - 1; i++) {
		left = findleft(height, heightSize, i);
		right = findright(height, heightSize, i);
		if (left >= 0 && right > 0) {
			int h = height[left] < height[right]? height[left]:height[right];
			for (j = left + 1; j < right; j++) {
				ret += h - height[j];
			}	
			i = right;
		}
	}

	return ret;
}

int main(int argc, char *argv[])
{
	//int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int height[] = {6,4,2,0,3,2,0,3,1,4,5,3,2,7};
	int ret = trap(height, sizeof(height) / 4);
	printf("%d\n", ret);

	return 0;
}
