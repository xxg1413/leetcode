#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            if (nums.size() < 2) return;

            int i = nums.size()-2;
            while (i >= 0 && nums[i] >= nums[i+1]) i--;
            if (i >= 0)
                swap (nums[i], *upper_bound (nums.rbegin(), 
                            nums.rend()-i-1, nums[i]));
            reverse (nums.begin()+i+1, nums.end());
        }
};

/*
 * input: vector<int>
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
    int err = 0;
    string buf;
    vector<int> v1, v2, saved_v;

    while (true) {
        cin >> v1;
        if (cin.eof()) break;
        saved_v = v1;
        v2 = v1;
        Solution().nextPermutation(v1);
        next_permutation (v2.begin(), v2.end());

        if (v2 != v1) {
            err = 1;
            cout << "input: " << saved_v << endl
                 << "ret: " << v1 << endl
                 << "expected: " << v2 << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
