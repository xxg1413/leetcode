#include "head.h"
static int Q; 
static char ***ret;
static int retsize;
static int retcur;

int locok(char **queen, int cur, int b)
{
	int i,j;
	for(i = 0; i< cur; i++)
	    for(j = 0; j < Q; j++) {
		if (queen[i][j] == 'Q') {
			if (i == cur || j == b) return 0;
			if (abs(i - cur) == abs(j - b)) return 0;
		}
	    }
	return 1;
}

void x8q(char **queen, int cur)
{
	if (cur == Q) return;
	if (cur == Q - 1) {
		int i;
		for(i = 0; i < Q;i ++) {
			if (locok(queen, cur, i)) {
				queen[cur][i] = 'Q';
				int k;
				for(k = 0; k < Q; k++) 
					memcpy(ret[retcur][k], queen[k], Q);
				retcur ++;
				queen[cur][i] = '.';
			}
		}
	} else {
		int i;
		for(i = 0; i < Q; i ++) {
			if (locok(queen, cur, i)) {
				queen[cur][i] = 'Q';
			        x8q(queen, cur + 1);
				queen[cur][i] = '.';
			}	
		}
	}
}

char*** solveNQueens(int n, int* returnSize) 
{
	int i, j;
	retcur = 0;
	switch(n) {
	case 1:case 2:case 3:case 4:case 5:case 6:retsize = 10;break;
	case 7:retsize = 40;break;
	case 8:retsize = 92;break;
	case 9:retsize = 352;break;
	default :retsize = 8192;
	}
	ret = malloc(sizeof(char **) * retsize);
	for (i = 0; i < retsize; i++) {
		ret[i] = (char **)malloc(sizeof(char *) * n);
		for (j = 0; j < n; j++) {
			ret[i][j] = (char *)malloc(sizeof(char) * (n + 1));
			ret[i][j][n] = '\0';
		}
	}
	char **queen = (char **)malloc(sizeof(char *) * n);
	for (i = 0; i < n; i++) {
		queen[i] = (char *)malloc(sizeof(char) * n);
		memset(queen[i], '.', n);
	}

	Q = n;
	x8q(queen, 0);
	*returnSize = retcur;
	return ret;
}
int main(int argc, char *argv[])
{
	int nq = 0;
	solveNQueens(atoi(argv[1]), &nq);
#if 1
	int i, j;
	for (i = 0; i < nq; i++) {
		for (j = 0; j < Q; j++)
			puts(ret[i][j]);
		printf("(%d)\n", i);	
	}
#endif
	return 0;
}
