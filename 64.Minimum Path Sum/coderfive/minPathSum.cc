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
        int minPathSum(vector<vector<int>>& grid) {
            if (grid.size() == 0 || grid[0].size() == 0) return 0;
            int n = grid.size(), m = grid[0].size();
            std::partial_sum (grid[0].begin(), grid[0].end(), grid[0].begin());
            for (int i = 1; i < n; i++) {
                grid[i][0] += grid[i-1][0];
                for (int j = 1; j < m; j++)
                    grid[i][j] += std::min(grid[i][j-1], grid[i-1][j]);
            }

            return grid[n-1][m-1];
        }
};

/*
 * input: vector<vector<int>> ## int
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
    vector<vector<int>> vvi, saved_vvi;
    int ret, expected;

    while (true) {
        cin >> vvi;
        if (cin.eof()) break;
        cin >> buf >> expected;
        saved_vvi = vvi;
        ret = Solution().minPathSum (vvi);
        if (ret != expected) {
            err = 1;
            cout << "input: " << saved_vvi << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
