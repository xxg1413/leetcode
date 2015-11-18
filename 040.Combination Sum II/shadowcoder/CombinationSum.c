#include "head.h"
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced,
 * assume caller calls free().
 */
int mycompar(const void *a, const void *b)
{
	int *x = (int *)a;
	int *y = (int *)b;
	if (*x > *y) return 1;
	return *x == *y? 0 : -1;
}

void dofun(int *nlist, int nsize, int *nmark, int left, int target, int **ret, int *col, 
		int *retsize, int *tmp, int *tmpsize)
{
	int i;

	if (target==0) {
		//tmp[(*tmpsize)++] = nlist[0];
		int *line = (int *)calloc(sizeof(int), *tmpsize);
		col[*retsize] = *tmpsize;
		memcpy(line, tmp, *tmpsize * sizeof(int));
		ret[*retsize] = line;
		(*retsize)++;
		return;
	}
	if (target < nlist[0]) return;
	for (i = left + 1; i < nsize; i++) {
		if (nmark[i]) continue;

		nmark[i] = 1;
		tmp[(*tmpsize)++] = nlist[i];
		int left = i;
		dofun(nlist, nsize, nmark, left, target - nlist[i], ret, col, retsize, tmp, tmpsize);
		(*tmpsize)--;
		nmark[i] = 0;
		while (nlist[i+1] == nlist[i]) i++;
	}
}

int **combinationSum2(int *nlist, int nsize, int target, int **col, int *retsize)
{
	qsort(nlist, nsize, sizeof(int), mycompar);

	int **ret = (int **)calloc(sizeof(int *), 8192);
	*col = (int *)calloc(sizeof(int), 8192);
	int tmp[8192] = {0};
	int tmpsize = 0;
	int nmark[8192] = {0};
	int left = -1;
	dofun(nlist, nsize, nmark, left, target, ret, *col, retsize, tmp, &tmpsize);
	return ret;
}

int main(void)
{
	int nlist[] = {2, 2, 3, 6, 7};
	int nsize = sizeof(nlist) / 4;
	int target = 7;
	int *col = NULL;
	int retsize = 0;
	int **ret = combinationSum2(nlist, nsize, target, &col, &retsize);
	int i, j;
	for (i = 0; i < retsize; i++) {
		for (j = 0; j < col[i]; j++) {
			printf("%d ", ret[i][j]);
		}
		printf("\n");
	}
	return 0;
}
