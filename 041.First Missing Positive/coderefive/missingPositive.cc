#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        /* assuming postive ints are distinctive from each other  */
        int firstMissingPositive(vector<int>& nums) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != i+1) {
                    int k = nums[i]-1;
                    if (nums[k] == nums[i]) continue;
                    nums[i] = nums[k];
                    nums[k] = k+1;
                    i--;
                }
            }
            int val = 1;
            for (int i = 0; i < nums.size(); i++, val++)
                if (nums[i] != val) return val;
            return val;
        }
};

/*
 * input: vector<int>
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
    int err = 0, success = 0, total = 0;
    string buf;
    vector<int> vi, saved_vi;
    int ret, expected;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        total++;
        saved_vi = vi;

        ret = Solution().firstMissingPositive(vi);
        vi = saved_vi;
        sort (vi.begin(), vi.end());
        expected = 1;
        int i = 0;
        while (i < vi.size() && vi[i] <= 0) i++;
        for (; i < vi.size(); i++) {
            if (vi[i] == expected)
                expected++;
            else
                break;
        }

        if (ret != expected) {
            err = 1;
            cout << "input: " << saved_vi << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
        else 
            success++;
    }

    if (err == 0)
        cout << "All tests passed!\n";
    else
        cout << "success rate " << success << "/" << total << endl;

    return 0;
}
