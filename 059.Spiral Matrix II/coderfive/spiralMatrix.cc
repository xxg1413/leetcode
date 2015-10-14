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
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> res (n, vector<int>(n, 0));
            int i = 0, half = n/2, idx = 1;

            for (; i < half; i++) {
                for (int j = i; j < n-i; j++, idx++)
                    res[i][j] = idx;
                for (int j = i+1; j < n-i-1; j++, idx++)
                    res[j][n-i-1] = idx;
                for (int j = n-1-i; j >= i; j--, idx++)
                    res[n-1-i][j] = idx;
                for (int j = n-2-i; j >= i+1; j--, idx++)
                    res[j][i] = idx;
            }
            if (idx == n*n) res[half][half] = idx;

            return res;
        }
};

/*
 * input: int ## vector<vector<int>>
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
    int err = 0, n;
    string buf;
    vector<vector<int>> expected, ret;

    while (true) {
        cin >> n;
        if (cin.eof()) break;
        cin >> buf >> expected;
        ret = Solution().generateMatrix(n);
        if (ret != expected) {
            err = 1;
            cout << "input: " << n << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
