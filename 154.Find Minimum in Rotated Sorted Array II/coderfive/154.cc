#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

class Solution {
public:
    int findMin(vector<int>& nums) {
	int sz = nums.size();
	if (sz == 0) return 0;
	int beg = 0, end = sz;
	int mid;
	while (beg+3 < end) {
	    mid = (beg+end)/2;
	    if (nums[beg] < nums[end-1]) return nums[beg];
	    if (nums[mid] > nums[beg]) beg = mid+1;
	    else if (nums[mid] < nums[beg]) end = mid+1;
	    else {
		mid++;
		while (mid < end && nums[mid] == nums[beg])
		    mid++;
		if (mid == end) end = (beg+end)/2;
		else if (nums[mid] < nums[beg]) return nums[mid];
		else beg = mid;
	    }
	}
	return *std::min_element(nums.begin()+beg, nums.begin()+end);
    }
};

int main() {
    vector<int> n {1,1,1,3};
    std::cout << Solution().findMin(n) << std::endl;
    vector<int> n2 {-4,-4,-3,-3,-3,-3,-3,-3,-3,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,0,0,
	0,0,0,0,0,0,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,
	3,3,3,4,4,4,5,5,5,5,5,6,6,6,6,6,7,7,7,7,8,
	8,8,8,8,8,8,9,9,10,10,10,10,-10,-10,-10,-9,-9,-9,-9,-8,-8,
	-8,-7,-7,-7,-6,-6,-6,-6,-5,-5,-5,-4,-4,-4,-4};
    std::cout << Solution().findMin(n2) << std::endl;

    return 0;
}
