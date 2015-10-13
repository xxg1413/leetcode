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
        bool canJump(vector<int>& nums) {
            if (nums.size() == 0) return false;
            int i, range = 0, n = nums.size();
            for (i = 0; range >= 0 && i < n; i++) {
                if (nums[i] > range) range = nums[i];
                range--;
                if (range >= n-i)
                    return true;
            }
            if (i == nums.size()) return true;
            return false;
        }
};

/*
 * input: vector<int> ## true|false
 */

template<typename T>
istream& operator >> (istream& in, vector<T>& vi) {
    T val;
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

template<typename T>
ostream& operator << (ostream& out, vector<T>& vi) {
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
    vector<int> vi;
    bool ret, expected;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        cin >> buf >> buf;
        if (buf == "true") expected = true;
        else expected = false;
        ret = Solution().canJump(vi);
        if (ret != expected) {
            err = 1;
            cout << "input: " << vi << endl
                 << "ret: " << std::boolalpha << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
