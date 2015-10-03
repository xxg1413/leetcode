#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.size() < 2) return nums.size();
            int i = 1, pos = 0;
            while (i < nums.size()) {
                while (i < nums.size() && nums[i] == nums[pos]) i++;
                if (i < nums.size()) nums[++pos] = nums[i++];
            }
            return pos+1;
        }
};

/*
 * input: vector<int> ## int vector<int>
 * vector<int> : {}
 *              | {int [, int]*}
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
    int err = 0, ret, expected;
    string buf;
    vector<int> vi, v2;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        cin >> buf >> expected >> v2;
        vector<int> saved_vi (vi);
        ret = Solution().removeDuplicates(vi);

        if (ret != expected || !equal (vi.begin(), vi.begin()+ret, v2.begin())) {
            err = 1;
            vi.resize(ret);
            cout << "input: " << saved_vi << endl
                 << "ret: " << ret << " " << vi << endl
                 << "expected: " << expected << " " << v2 << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
