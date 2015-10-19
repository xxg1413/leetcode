#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int lo = 0, hi = nums.size(), mid;
            vector<int> res {-1, -1};

            /* std::lower_bound */
            while (lo < hi) {
                mid = (lo+hi)/2;
                if (nums[mid] < target)
                    lo = mid+1;
                else
                    hi = mid;
            }
            if (hi == nums.size() || nums[hi] != target) 
                return res;

            res[0] = hi;
            lo = hi;
            hi = nums.size();

            /* std::upper_bound */
            while (lo < hi) {
                mid = (lo+hi)/2;
                if (nums[mid] <= target)
                    lo = mid+1;
                else
                    hi = mid;
            }
            res[1] = hi-1;

            return res;
        }
};

/*
 * input: vector<int> target
 * vector<int>: {}
 *             | {int [, int]*}
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
            return in;
        }
        else if (in.peek() == ',') in.get();
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
    int err = 0, target;
    string buf;
    vector<int> vi, ret, expected {-1, 1};

    while (true) {
        cin >> vi;
        if (cin.eof()) break;

        cin >> target;
        ret = Solution().searchRange(vi, target);
        expected[0] = std::lower_bound (vi.begin(), vi.end(), target)-vi.begin();
        if (expected[0] == vi.size() || vi[expected[0]] != target) {
            expected = vector<int>({-1, -1}); 
        }
        else {
            expected[1] = std::upper_bound (vi.begin(), vi.end(), target)-vi.begin()-1;
        }
        if (ret != expected) {
            err = 1;
            cout << "input: " << vi << "  " << target << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
