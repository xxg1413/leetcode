/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char pho[10][5] = {
	{},
	{},
	{'a','b','c'},
	{'d','e','f'},
	{'g','h','i'},
	{'j','k','l'},
	{'m','n','o'},
	{'p','q','r','s'},
	{'t','u','v'},
	{'w','x','y','z'}
};

void fun(char *digits, char **out, int *op, char *line, int *linesize)
{
	if (!*digits && line[0]) {
		memcpy(out[(*op)++],  line, strlen(line) + 1);
	} else {
		char *alpha = pho[*digits - '0'];
		while (*alpha) {
			line[*linesize] = *alpha;
			(*linesize)++;
			fun(digits+1, out, op, line, linesize);
			(*linesize)--;
			alpha++;
		}
	}
}
char** letterCombinations(char* digits, int* returnSize) 
{
	int len = strlen(digits);
	if (!len) return NULL;
	int num = (int)pow(4.0, len) + 1;
	char **out = (char **)calloc(sizeof(char *), num);
	int i, linesize = 0;
	*returnSize = 0;
	for (i = 0; i < num; i++)
		out[i] = (char *)calloc(sizeof(char), len + 1);
	fun(digits, out, returnSize, out[num - 1], &linesize);
	return out;
}
