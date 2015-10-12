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
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> res;
            if (nums.size() == 0) return res;

            std::sort (nums.begin(), nums.end());
            do {
                res.push_back(nums);
            } while (std::next_permutation(nums.begin(), nums.end()));

            return res;
        }
};

/*
 * input: vector<int> ## vector<vector<int>>
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
    vector<int> vi, saved_vi;
    vector<vector<int>> ret, expected;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        saved_vi = vi;
        ret = Solution().permuteUnique(vi);
        cin >> buf >> expected;
        std::sort (ret.begin(), ret.end());
        std::sort (expected.begin(), expected.end());

        if (ret != expected) {
            err = 1;
            cout << "input: " << saved_vi << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
