class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int with = nums[0], without = 0;
        int tmp;
        for (int i = 1; i < nums.size(); i++) {
            tmp = std::max(with, without);
            with = std::max(without+nums[i], with);
            without = tmp;
        }

        return std::max (with, without);
    }
};
