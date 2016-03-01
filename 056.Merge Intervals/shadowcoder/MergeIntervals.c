int intercmp(const void *a, const void *b)
{
	struct Interval *x = (struct Interval *)a;
	struct Interval *y = (struct Interval *)b;
	if (x->start < y->start) return -1;
	if (x->start > y->start) return 1;
	if (x->end < y->end) return -1;
	if (x->end > y->end) return 1;
	return 0;
}
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) 
{
	*returnSize = 0;
	if (!intervalsSize) return NULL;
	qsort(intervals, intervalsSize, sizeof(struct Interval), intercmp);
	int i;
	for (i = 1; i < intervalsSize; i++) {
		if (intervals[i].start <= intervals[*returnSize].end)
			intervals[*returnSize].end = intervals[i].end > intervals[*returnSize].end?intervals[i].end:intervals[*returnSize].end;
		else {
			(*returnSize)++;
			intervals[*returnSize].start = intervals[i].start;
			intervals[*returnSize].end = intervals[i].end;
		}
	}
	(*returnSize)++;
	struct Interval *ret = (struct Interval *)malloc(sizeof(struct Interval) * (*returnSize));
	memcpy(ret, intervals, sizeof(struct Interval) * (*returnSize));
	return ret;
}
