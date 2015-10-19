#include "head.h"
#define MIN(x,y) ((x) > (y)? (y) : (x))

int maxArea(int* height, int heightSize)
{
    int area = 0, k;
    int i = 0, j = heightSize - 1;
    while (i < j) {
    	k = MIN(height[i], height[j]) * (j - i);
	if (k > area) area = k;
	if (height[i] <= height[j]) i++;
	else j--;
    }
    return area;
}

int main(int argc, char *argv[])
{
	int i[] = {1, 3, 5, 7, 9};
	printf("%d\n", maxArea(i, 5));
}
