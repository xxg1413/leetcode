#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEFT	0
#define RIGHT	1
char* convert(char* s, int numRows) 
{
	if (numRows == 1) return s;
	int i, rowo, magic = 2 * numRows - 2;
	int k = 0, left, right, past = RIGHT, prow = -1;
	int slen = strlen(s);
	char *tmp = (char *)calloc(sizeof(char), slen + 1);
	for (rowo = 0; rowo < numRows; rowo++) {
		int row = rowo;
		left = magic - 2 * row;
		right = 2 * row;
		past = RIGHT;
		while (row < slen) {
			if (row != prow) tmp[k++] = s[row];
			prow = row;
			if (past == RIGHT) {
				past = LEFT;	
				row += left;
			} else {
				past = RIGHT;
				row += right;
			}
		}
	}
	return tmp;
}

int main(int argc, char *argv[])
{
	int num = atoi(argv[2]);
	char *p = convert(argv[1], num);
	printf("%s\n", p);
	return 0;
}
