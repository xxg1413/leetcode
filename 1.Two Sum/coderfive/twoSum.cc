#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<pair<int, int>> vp;
            vector<int> res(2);
            vp.resize (nums.size());
            for (int i = 0; i < nums.size(); i++) {
                vp[i].first = nums[i];
                vp[i].second = i;
            }
            sort (vp.begin(), vp.end());

            res[0] = 0;
            res[1] = vp.size()-1;
            /* match must exist */
            while (res[0] < res[1]) {
                while (vp[res[0]].first + vp[res[1]].first > target)
                    res[1]--;
                if (vp[res[0]].first + vp[res[1]].first == target) {
                    res[0] = vp[res[0]].second + 1;
                    res[1] = vp[res[1]].second + 1;
                    if (res[0] > res[1]) swap(res[0], res[1]);
                    break;
                }
                res[0]++;
            }
            return res;
        }
};

/**
 * input: int+ 't' int [notes to be ignored]
 **/
int main() {
    vector<int> v;
    int target;
    string buf;

    while (true) {
        cin >> buf;
        if (cin.eof()) return 0;
        if (buf[0] == 't') {
            cin >> target;
            auto res = Solution() . twoSum (v, target);
            cout << res[0] << ' ' <<  res[1] << '\n';
            v.clear();
            cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        v.push_back (stoi(buf));
    }


    return 0;
}
