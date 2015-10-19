#include "head.h"
int *findaim(int *n, int l, int aim)
{
	static int ret[2];
	ret[0] = ret[1] = -1;
	int left = 0, right = l - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if(n[mid] < aim)
			left = mid + 1;
		else
			right = mid - 1;
	}
	ret[0] = left;
	left = 0, right = l - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (n[mid] > aim)
			right = mid - 1;
		else
			left = mid + 1;	
	}	
	ret[1] = left;
	return ret;
}

int *findmid(int *n1, int l1, int *n2, int l2, int midnum)
{
	int left = 0, right = l1 - 1, mid;
	while(left <= right) {
		mid = (left + right) / 2;
		int *n2loc = findaim(n2, l2, n1[mid]);
		if ((mid + n2loc[0]) > midnum) {
			right = mid - 1;
		} else if((mid + n2loc[1]) < midnum) {
			left = mid + 1;
		} else {
			return n1 + mid;
		}
	}
	return NULL;
}

double findMedianSortedArrays(int* nums1, int l1, int* nums2, int l2) 
{
	if (!l1 && !l2) return 0.0;
	int m1, m2;
	int *p1, *p2;
	m1 = (l1 + l2 - 1) / 2;
	m2 = m1;
	if ((l1 + l2) % 2 == 0)
		m2 += 1;
	p1 = findmid(nums1, l1, nums2, l2, m1);
	if (!p1)
		p1 = findmid(nums2, l2, nums1, l1, m1);
		
	p2 = findmid(nums1, l1, nums2, l2, m2);
	if (!p2)
		p2 = findmid(nums2, l2, nums1, l1, m2);
	return 1.0 * (*p1 + *p2) / 2;
}

int main(int argc, char *argv[])
{
	int n1[] = {};
	int n2[] = {1};
	printf("%.2f\n", findMedianSortedArrays(n1, sizeof(n1) / 4, n2, sizeof(n2) / 4));
	
	int n3[] = {};
	int n4[] = {2, 3};
	printf("%.2f\n", findMedianSortedArrays(n3, sizeof(n3) / 4, n4, sizeof(n4) / 4));

	int n7[] = {1};
	int n8[] = {1};
	printf("%.2f\n", findMedianSortedArrays(n7, sizeof(n7) / 4, n8, sizeof(n8) / 4));	

	int n5[] = {1, 2};
	int n6[] = {1, 2};
	printf("%.2f\n", findMedianSortedArrays(n5, sizeof(n5) / 4, n6, sizeof(n6) / 4));
}
