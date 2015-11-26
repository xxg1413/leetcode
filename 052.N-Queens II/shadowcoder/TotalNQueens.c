#include "head.h"
static int Q; 
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
				retcur++;
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

int totalNQueens(int n) 
{
	int i, j;
	retcur = 0;

	char *queen[100] = {0};
	for (i = 0; i < n; i++) {
		queen[i] = (char *)malloc(sizeof(char) * n);
		memset(queen[i], '.', n);
	}

	Q = n;
	x8q(queen, 0);
	return retcur;
}
int main(int argc, char *argv[])
{
	int nq = 0;
	int ret = totalNQueens(atoi(argv[1]));
#if 1
		printf("(%d)\n", ret);	
#endif
	return 0;
}
