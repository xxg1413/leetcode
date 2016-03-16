class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int st = 0, end = 0, sum = 0, len = nums.size();
        while (end < nums.size()) {
            sum += nums[end++];
            if (sum >= s) {
                while (sum - nums[st] >= s) sum -= nums[st++];
                if (len > end-st) len = end-st;
            }
        }
        if (sum < s) return 0;
        return len;
    }
};
