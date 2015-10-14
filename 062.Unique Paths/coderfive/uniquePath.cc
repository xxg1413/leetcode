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
        int uniquePaths(int m, int n) {
            if (m == 0 || n == 0) return 0;
            vector<vector<int>> vvi (m, vector<int>(n, 1));
            for (int i = 1; i < m; i++)
                for (int j = 1; j < n; j++) {
                    vvi[i][j] = vvi[i-1][j] + vvi[i][j-1];
                }
            return vvi[m-1][n-1];
        }
};

/*
 * input: int int ## int
 */

int main() {
    int err = 0, ret, expected, m, n;
    string buf;

    while (true) {
        cin >> m;
        if (cin.eof()) break;
        cin >> n >> buf >> expected;
        ret = Solution().uniquePaths(m, n);
        if (expected != ret) {
            err = 1;
            cout << "input: " << m << "  " << n << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
