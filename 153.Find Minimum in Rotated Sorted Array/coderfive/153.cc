class Solution {
public:
    int findMin(vector<int>& nums) {
	int beg = 0, end = nums.size();
	int mid;
	if (nums[0] < nums.back()) return nums[0];

	while (beg+3 < end) {
	    mid = (beg+end)/2;
	    if (nums[mid] > nums[beg]) beg = mid;
	    else end = mid+1;
	}
	return *std::min_element(nums.begin()+beg, nums.begin()+end);
    }
};
