struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) 
{
	struct Interval *ret = (struct Interval *)malloc(sizeof(struct Interval) * (intervalsSize + 1));
	if (!intervalsSize) {
		*returnSize = 1;
		ret[0].start = newInterval.start;
		ret[0].end = newInterval.end;
		return ret;
	}
	int i, k = 0, ido = 0;
	for (i = 0; i < intervalsSize; i++) {
		if (!ido && newInterval.start < intervals[i].start) {
			ret[k].start = newInterval.start;
			ret[k++].end = newInterval.end;
			ido = 1;
		}
		ret[k].start = intervals[i].start;
		ret[k++].end = intervals[i].end;
	}
	if (k == intervalsSize) {
		ret[k].start = newInterval.start;
		ret[k++].end = newInterval.end;
	}
	*returnSize = 0;
	for (i = 1; i < intervalsSize + 1; i++) {
		if (ret[i].start <= ret[*returnSize].end)
			ret[*returnSize].end = ret[i].end > ret[*returnSize].end?ret[i].end:ret[*returnSize].end;
		else {
			(*returnSize)++;
			ret[*returnSize].start = ret[i].start;
			ret[*returnSize].end = ret[i].end;
		}
	}
	(*returnSize)++;
	return ret;	
}
