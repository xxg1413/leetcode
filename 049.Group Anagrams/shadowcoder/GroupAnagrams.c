#define WORDMAXLEN 32
int charcmp(const void *a, const void *b)
{
	char *x = (char *)a;
	char *y = (char *)b;
	if (*x > *y) return 1;
	return *x == *y? 0 : -1;
}
int stringcmp(const void *a, const void *b)
{
	char **x = (char **)a;
	char **y = (char **)b;
	return strcmp(*x, *y);
}
int strlencmp(const void *a, const void *b)
{
	char **x = (char **)a;
	char **y = (char **)b;
	int lena = strlen(*x);
	int lenb = strlen(*y);
	if (lena > lenb) return 1;
	return lena==lenb?0:-1;
}
struct node {
	char word[WORDMAXLEN];
	int wlen;
	int group;
	struct node *next;
};
static struct node *hashtab[2039] = {0};
void pushhash(char *str, int group)
{
	struct node *newn = (struct node *)malloc(sizeof(struct node));
	newn->wlen = strlen(str);
	newn->group = group;
	memcpy(newn->word, str, newn->wlen + 1);
	qsort(newn->word, newn->wlen, sizeof(char), charcmp);
	int i, sum = 0;
	for (i = 0; i < newn->wlen; i++)
		sum += str[i];
	sum *= newn->wlen;
	sum %= 2039;
	newn->next = hashtab[sum];
	hashtab[sum] = newn;
}

int pophash(char *str)
{
	int len = strlen(str);
	char tmp[WORDMAXLEN];
	memcpy(tmp, str, len + 1);
	qsort(tmp, len, sizeof(char), charcmp);
	int i, sum = 0;
	for (i = 0; i < len; i++)
		sum += str[i];
	sum *= len;
	sum %= 2039;
	struct node *no = hashtab[sum];
	while (no) {
		if (no->wlen < len) break;
		//printf("word: %s, tmp = %s line: %d\n", no->word, tmp, )
		if (!strcmp(no->word, tmp))
			return no->group;
		no = no->next;
	}
	return -1;
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) 
{
	int i, loc;
	memset(hashtab, 0, 2039 * (sizeof(struct node *)));
	char ***group = (char ***)malloc(sizeof(char **) * strsSize);
	for (i = 0; i < strsSize; i++)
		group[i] = (char **)malloc(sizeof(char *) * 128);
	*columnSizes = (int *)calloc(sizeof(int), strsSize);
	*returnSize = 0;
	qsort(strs, strsSize, sizeof(char *), strlencmp);
	for (i = 0; i < strsSize; i++) {
		//printf("i = %d, str = %s\n", i, strs[i]);
		if ((loc = pophash(strs[i])) >= 0)
			group[loc][columnSizes[0][loc]++] = strs[i];
		else {	
			group[*returnSize][columnSizes[0][*returnSize]++] = strs[i];
			pushhash(strs[i], (*returnSize)++);
		}
	}
	/*  */
	for (i = 0; i < *returnSize; i++) {
		qsort(group[i], columnSizes[0][i], sizeof(char *), stringcmp);
	}
	return group;
}
