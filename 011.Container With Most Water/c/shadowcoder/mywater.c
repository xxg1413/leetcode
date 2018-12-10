#define MIN(x,y) ((x) > (y)? (y) : (x))
int maxArea(int* height, int heightSize)
{
    int area = 0;
    int maxi, max = 0;
    int i, j, k;
    for (i = 0; i < heightSize; i++)
	    if (height[i] > max) {
	    	max = height[i];
		maxi = i;
	    }

    for (i = 0; i <= maxi; i++) {
    	for (j = heightSize - 1; j >= maxi; j--) {
		k = MIN(height[i], height[j]) * (j - i);
		if (k > area) area = k;
	}
    }
    return area;
}
