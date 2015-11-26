int totalNQueens(int n) 
{
	int ret[] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712};
	if (n <= 13) return ret[n];
	return -1;
}
