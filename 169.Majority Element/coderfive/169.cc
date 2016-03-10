class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int count = 0;
        for (auto n : nums) {
            if (n == res) count++;
            else count--;
            if (count <= 0) {
                res = n;
                count = 1;
            }
        }
        return res;
    }
};
