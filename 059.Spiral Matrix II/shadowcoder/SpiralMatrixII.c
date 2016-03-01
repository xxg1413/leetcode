#include "head.h"
/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) 
{
	int **ret = (int **)malloc(sizeof(int *) * n);
	int i;
	for(i = 0; i < n; i++)
		ret[i] = (int *)malloc(sizeof(int) * n);
	int loop = n / 2;
	int north = 0;
	int south = n - 1;
	int west = 0;
	int east = n - 1;
	int k = 1;
	while (loop--) {
		for (i = west; i <= east; i++)
			ret[north][i] = k++;
		for (i = north + 1; i <= south - 1; i++)
			ret[i][east] = k++;
		for (i = east; i >= west; i--)
			ret[south][i] = k++;
		for (i = south - 1; i >= north + 1; i--)
			ret[i][west] = k++;
		north++, south--;
		west++, east--;
	}	
	loop = n / 2;
	if (n % 2) ret[loop][loop] = k;
	return ret;
}

int main(int argc, char *argv[])
{
	int n = 4;
	int **ret = generateMatrix(n);

	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", ret[i][j]);
		printf("\n");
	}
	return 0;
}
