class Solution {
public:
    int maxProduct(vector<int>& nums) {
	if (nums.size() == 0) return 0;
	int neg_max = nums[0], pos_max = nums[0], real_max = nums[0];
	int a1, a2;
	for (int i = 1; i < nums.size(); i++) {
	    int n = nums[i];
	    a1 = neg_max * n;
	    a2 = pos_max * n;
	    neg_max = std::min(n, std::min(a1, a2));

	    pos_max = std::max(n, std::max(a1, a2));
	    if (real_max < pos_max) real_max = pos_max;
	}
	return real_max;
    }
};
