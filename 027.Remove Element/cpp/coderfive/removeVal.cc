#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int i = 0, pos = 0;

            while (i < nums.size()) {
                if (nums[i] == val) i++;
                else nums[pos++] = nums[i++];
            }

            return pos;
        }
};

/*
 * input: vector<int> int ## int vector<int>
 * vector<int>: {}
 *             | {int [, int]*}
 */

ostream& operator << (ostream& out, vector<int>& v) {
    out << "{";
    if (v.size() != 0)
        out << v[0];
    for (int i = 1; i < v.size(); i++)
        out << ", " << v[i];
    out << "}";

    return out;
}

istream& operator >> (istream& in, vector<int>& v) {
    int val;
    v.clear();
    while (!in.eof() && isspace(in.peek())) in.get();
    if (in.eof()) return in;
    in.get();

    while (true) {
        while (isspace(in.peek())) in.get();
        if (in.peek() == '}') {
            in.get();
            break;
        }
        else if (in.peek() == ',') in.get();

        in >> val;
        v.push_back(val);
    }

    return in;
}

int main() {
    int err = 0, n, ret, val;
    string buf;
    vector<int> vi, expected_v;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        vector<int> saved_vi = vi;
        cin >> val >> buf >> n >> expected_v;

        ret = Solution().removeElement(vi, val);
        if (ret != n || !equal(vi.begin(), vi.begin()+ret, expected_v.begin())) {
            err = 1;
            vi.resize(ret);
            cout << "input: " << saved_vi << " " << val << endl
                 << "ret: " << ret << "  " << vi << endl
                 << "expected: " << n << "  " << expected_v << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
