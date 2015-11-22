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
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> res;
            vector<int> idx;
            idx.resize(k);
            idx[0] = 0;
            int i = 0;
            while (true) {
                while (i >= 0 && (++idx[i]+k-i-1) > n) i--;
                if (i < 0) break;
                while (i != k-1) {
                    idx[i+1] = idx[i]+1;
                    i++;
                }
                res.push_back (idx);
            }

            return res;
        }
};

/*
 * input: int int ## vector<vector<int>>
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
    int n, k;

    while (true) {
        cin >> n;
        if (cin.eof()) break;
        cin >> k >> buf >> expected;
        res = Solution().combine(n, k);
        for (auto v : res)
            std::sort (v.begin(), v.end());
        std::sort (res.begin(), res.end());
        for (auto v : expected)
            std::sort (v.begin(), v.end());
        std::sort (expected.begin(), expected.end());

        if (res != expected) {
            err = true;
            cout << "input: " << n << " " << k << endl
                 << "expected: " << expected << endl
                 << "res: " << res << endl << endl;
        }
    }

    if (!err)
        cout << "All tests passed!\n";

    return 0;
}
