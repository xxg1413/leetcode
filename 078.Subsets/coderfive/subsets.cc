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
        vector<vector<int>> subsets(vector<int>& nums) {
            std::sort (nums.begin(), nums.end());
            vector<vector<int>> res;
            vector<int> idx;
            res.push_back(vector<int>());
            idx.resize(nums.size()+1);
            idx[0] = -1;
            int i = 0, sz = nums.size(), j;
            while (true) {
                while (i >= 0 && ++idx[i] == sz) i--;
                if (i < 0) break;
                while (idx[i] < sz) {
                    res.push_back(vector<int>());
                    auto& v = res.back();
                    for (j = 0; j <= i; j++)
                        v.push_back(nums[idx[j]]);
                    idx[i+1] = idx[i]+1;
                    i++;
                }
                i--;
            }

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
    bool err = false;
    string buf;
    vector<vector<int>> expected, res;
    vector<int> nums;

    while (true) {
        cin >> nums;
        if (cin.eof()) break;
        cin >> buf >> expected;
        res = Solution().subsets(nums);

        std::sort (expected.begin(), expected.end());
        std::sort (res.begin(), res.end());

        if (res != expected) {
            err = true;
            cout << "input: " << nums << endl
                 << "result: " << res << endl
                 << "expected: " << expected << endl << endl;
        }

    }

    if (!err)
        cout << "All tests passed!\n";

    return 0;
}
