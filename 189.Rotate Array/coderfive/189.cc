#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int st = 0, end = nums.size(), mid = end-k;
        int s_st, s_end, s_mid;
        while (mid != st && mid != end) {
            if (mid-st > end-mid) {
                s_st = st;
                s_end = mid;
                s_mid = mid - (end-mid);
                st = s_mid;
            }
            else {
                s_st = mid;
                s_end = end;
                s_mid = mid+mid-st;
                end = s_mid;
            }
            while (mid != end) std::swap (nums[st++], nums[mid++]);
            st = s_st;
            mid = s_mid;
            end = s_end;
        }
    }
};

int main() {
    vector<int> v {1,2,3};
    Solution().rotate(v, 2);
    std::copy (v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}

