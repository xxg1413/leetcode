/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define PERM 2039
struct twoint {
	int index;
	int value;
	struct twoint *next;
};

void add2hash(struct twoint *hash[PERM], struct twoint *val)
{
	int in = val->value % PERM;
	if (in < 0) in += PERM;
	val->next = hash[in];
	hash[in] = val;
}

int findhash(struct twoint *hash[PERM], int val) 
{
	int in = val % PERM;
	if (in < 0) in += PERM;
	struct twoint *p = hash[in];
	while (p) {
		if (p->value == val) return p->index;
		p = p->next;
	}
	return -1;
}

/** memory leak */
int* twoSum(int* nums, int numsSize, int target) 
{
	struct twoint *hash[PERM] = {0};
	int *ret = NULL;
	int i, f;
	for(i = 0; i < numsSize; i++) {
		if ((f = findhash(hash, target - nums[i])) < 0) {
			struct twoint *t = (struct twoint *)calloc(sizeof(struct twoint), 1);
			t->index = i + 1;
			t->value = nums[i];
			add2hash(hash, t);
		} else {
			ret = (int *)calloc(sizeof(int), 2);
			ret[0] = f;
			ret[1] = i + 1;
			goto out;
		}
	}

out:
	return ret;
}
