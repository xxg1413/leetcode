int mycompar(const void *a, const void *b)
{
	int *x = (int *)a;
	int *y = (int *)b;
	if (*x > *y) return 1;
	return *x == *y? 0 : -1;
}
static int *glonums = NULL;
static int gloncnt;
static int **out = NULL;
static int outsize = 0;		/* malloc size */
static int ocnt = 0;		/* out location */
void fun(int *nums, int nsize)
{
	if (!nsize) {
		if (ocnt >= outsize) {
			outsize *= 2;
			int **tmp = (int **)malloc(sizeof(int *) * outsize);
			int tsize;
			for (tsize = 0; tsize < outsize / 2; tsize++)
				tmp[tsize] = out[tsize];
			//memcpy(tmp, out, (sizeof(int *)) * (outsize / 2));
			free(out);
			out = tmp;
			//out = (int **)realloc(out, outsize);
		}
			
		out[ocnt] = (int *)malloc(sizeof(int) * gloncnt);
		memcpy(out[ocnt++], glonums, sizeof(int) * gloncnt);
		return;
	}
	int i, tmp, k;
	for (i = 0; i < nsize; i++) {
		//if (i && (nums[0] == nums[i] || nums[i] == nums[i-1])) continue;
		for (k = 0; k < i; k++) 
			if (nums[k] == nums[i]) break;
		if (k != i) continue;
		tmp = nums[0];
		nums[0] = nums[i];
		nums[i] = tmp;
		fun(nums + 1, nsize - 1);
		tmp = nums[0];
		nums[0] = nums[i];
		nums[i] = tmp;
	}
}
int** permuteUnique(int* nums, int numsSize, int* returnSize) 
{
	int i = numsSize;
	glonums = nums;
	gloncnt = numsSize;
	ocnt = 0;
	outsize = 8192;
	out = (int **)malloc(sizeof(int *) * outsize);
	
	qsort(nums, numsSize, sizeof(int), mycompar);
	fun(nums, numsSize);

	*returnSize = ocnt;
	return out;
}  
