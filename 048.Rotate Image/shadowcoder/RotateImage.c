void rotate(int** matrix, int matrixRowSize, int matrixColSize) 
{
	int i, j, n = matrixRowSize, n1 = n - 1;
	int **tmp = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++)
		tmp[i] = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			tmp[j][n1 - i] = matrix[i][j];
		}
	}
	for (i = 0; i < n; i++)
		matrix[i] = tmp[i];
}
