#include "head.h"
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) 
{
	int *ret = (int *)malloc(sizeof(int) * matrixRowSize * matrixColSize);
	int k = 0, i;
	int over = matrixRowSize > matrixColSize? matrixColSize : matrixRowSize;
	over -= 1;
	int low = 0;

	int north = 0;
	int south = matrixRowSize - 1;
	int east = matrixColSize - 1;
	int west = 0;
	while (low <= over) {
		for (i = west; i <= east; i++)
			ret[k++] = matrix[north][i];
		for (i = north + 1; i <= south - 1; i++)
			ret[k++] = matrix[i][east];
		for (i = east; north != south && i >= west; i--)
			ret[k++] = matrix[south][i];
		for (i = south - 1; west != east && i >= north + 1; i--)
			ret[k++] = matrix[i][west];
		north++,south--;
		west++,east--;
		low++, over--;
	}

	return ret;
}

int main(int argc, char *argv[])
{
	int *matrix[100] = {0};
	int line1[10] = {1,2,3,4,5,6,7,8,9,10};
	matrix[0] = line1;
	int *ret = spiralOrder(matrix, 1, 10);

	return 0;
}
