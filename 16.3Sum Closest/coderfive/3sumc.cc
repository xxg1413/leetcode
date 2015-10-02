#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            nums.push_back (numeric_limits<int>::min());
            int res = accumulate(nums.begin(), nums.begin()+3, 0);
            sort(nums.begin(), nums.end());
            if (nums[0] == nums[1]) nums[0]++;

            int i, j, sum, end;
            for (i = 1; i < nums.size(); i++) {
                while (i < nums.size() && nums[i] == nums[i-1]) i++;
                for (j = i+1, end = nums.size()-1; j < end; ) {
                    while (j < end && (sum = nums[i]+nums[j]+nums[end]) > target) end--;
                    if (j < end) {
                        sum = nums[i]+nums[j]+nums[end];
                        if (abs(sum-target) < abs(res-target)) res = sum;
                    }
                    if (end < nums.size()-1) {
                        sum = nums[i]+nums[j]+nums[end+1];
                        if (abs(sum-target) < abs(res-target)) res = sum;
                    }
                    j++;
                    while (j < end && nums[j] == nums[j-1]) j++;
                    if (res == target) return res;
                }
            }

            return res;
        }
};

/*
 * input: vector<int> int ## res
 *        vector<int>: {}
 *                    | {int [, int]*}
 */

istream& operator >> (istream& in, vector<int>& vi) {
    int val;
    vi.clear();
    while (!in.eof() && isspace(in.peek())) in.get();
    if (in.eof()) return in;
    in.get();

    while (true) {
        while (isspace(in.peek())) in.get();
        if (in.peek() == '}') {
            in.get();
            break;
        }
        if (in.peek() == ',') in.get();
        in >> val;
        vi.push_back(val);
    }

    return in;
}

ostream& operator << (ostream& out, vector<int>& vi) {
    out << "{";
    if (vi.size() != 0)
        out << vi[0];
    for (int i = 1; i < vi.size(); i++)
        out << ", " << vi[i];
    out << "}";

    return out;
}

int main() {
    int err = 0, target, res, ret;
    string buf;
    vector<int> vi;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        cin >> target >> buf >> res;
        ret = Solution().threeSumClosest(vi, target);
        if (ret != res) {
            err = 1;
            cout << "input: " << vi << " " << target << endl
                 << "ret: " << ret << endl
                 << "expected: " << res << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
