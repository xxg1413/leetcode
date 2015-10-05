#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int start = 0, mid, end = nums.size()-1;
            while (start+1 < end) {
                mid = (start+end) / 2;
                if (nums[mid] > nums[start]) {
                    if (target >= nums[start] && target <= nums[mid])
                        end = mid;
                    else 
                        start = mid;
                }
                else {
                    if (target >= nums[mid] && target <= nums[end])
                        start = mid;
                    else
                        end = mid;
                }
            }
            int idx = find (nums.begin()+start, nums.end()+1, target) - nums.begin();

            if (idx < nums.size()) return idx;
            else return -1;
        }
};

/*
 * input: vector<int> int
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
    int err = 0, target, ret, expected;
    string buf;
    vector<int> vi;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        cin >> target;
        ret = Solution().search(vi, target);
        expected = find (vi.begin(), vi.end(), target) - vi.begin();
        if (expected == vi.size()) expected = -1;

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
