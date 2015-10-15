#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
#include <cstdlib>
using namespace std;

class Solution {
    public:
        int climbStairs(int n) {
            if (n == 2) return 2;
            if (n <= 1) return 1;
            int mat[4] = {1,1,1,0};
            int res[4] = {1,0,1,0};
            n -= 2;
            while (n) {
                if (n & 1)
                    matrix_mul (res, mat);
                matrix_mul (mat, mat);
                n >>= 1;
            }

            return 2*res[0] + res[1];
        }
        void matrix_mul (int* lhs, int* rhs) {
            int loc[4];
            loc[0] = lhs[0]*rhs[0] + lhs[1]*rhs[2];
            loc[1] = lhs[0]*rhs[1] + lhs[1]*rhs[3];
            loc[2] = lhs[2]*rhs[0] + lhs[3]*rhs[2];
            loc[3] = lhs[2]*rhs[1] + lhs[3]*rhs[3];
            std::memcpy (lhs, loc, sizeof(loc));
        }
};

/*
 * input: int ## int
 */

int main() {
    int err = 0, n, ret, expected;
    string buf;

    while (true) {
        cin >> n;
        if (cin.eof()) break;
        cin >> buf >> expected;
        ret = Solution().climbStairs(n);
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
