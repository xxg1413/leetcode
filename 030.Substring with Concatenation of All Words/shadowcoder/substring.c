#include "head.h"
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void fun(char* start, char* s, char** words, int wordsSize, int *mark, int *ret, int* returnSize)
{
	int marksize = 0;
	int wlen = strlen(words[0]);
	int wordstr = wlen * wordsSize;
	int remain = wordsSize;
	int i;
	while (strlen(s) >= wordstr) {
		char *move = s + marksize * wlen;
		//remain = wordsSize - marksize;
		while (remain) {
			for (i = 0;i < wordsSize; i++) {
				if (mark[i]) continue;
				if (!strncmp(words[i], move, wlen)) {
					mark[i] = 1;
					marksize++;
					remain--;
					break;
				}	
			}
			if (i >= wordsSize) break;
			move += wlen;
		}
		if (!remain) {
			ret[(*returnSize)++] = s - start;
		}
		for (i = 0; i < wordsSize; i++) {
			if (!strncmp(words[i], s, wlen)) {
					mark[i] = 0;
					remain++;
					marksize--;
					break;
			}
		}
		for (i = 0; i < wordsSize; i++) mark[i] = 0;
		s += 1;
		remain = wordsSize;
		marksize = 0;
	}
}
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) 
{
	*returnSize = 0;
	int *mark = (int *)calloc(sizeof(int), wordsSize);
	int *ret = (int *)calloc(sizeof(int), 8192);
	fun(s, s, words, wordsSize, mark, ret, returnSize);
	return ret;
}
int main(int argc, char *argv[])
{
	//char s[] = {"a"};
	//char *words[2] = {"a"};
	//char s[] = {"barfoothefoobarman"};
	//char *words[2] = {"foo", "bar"};
	//char s[] = {"barfoofoobarthefoobarman"};
	//char *words[] = {"bar","foo","the"};
	//char s[] = {"wordgoodgoodgoodbestword"};
	//char *words[] = {"word","good","best","good"};
	//char s[] = {"lingmindraboofooowingdingbarrwingmonkeypoundcake"};
	//char *words[] = {"fooo","barr","wing","ding","wing"};
	char s[] = {"aaaaaaaa"};
	char *words[] = {"aa","aa","aa"};

	int size = 0;
	int *ret = findSubstring(s, words, 3, &size);
	int i;
	for (i = 0; i < size; i++)
		printf("%d\n", ret[i]);
	return 0;
}
