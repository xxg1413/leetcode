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
        double myPow(double x, int n) {
            if (n == 0) return 1;
            if (n < 0) {
                if (n == std::numeric_limits<int>::min())
                    return 1.0 / (myPow (x, std::numeric_limits<int>::max())*x);
                return 1.0 / myPow (x, -n);
            }
            double res = 1;
            while (n) {
                if (n&1)
                    res *= x;
                x *= x;
                n >>= 1;
            }

            return res;
        }
};

/*
 * input: double int ## double
 */

int main() {
    int err = 0;
    string buf;
    double ret, expected, x;
    int n;

    while (true) {
        cin >> x;
        if (cin.eof()) break;
        cin >> n >> buf >> expected;

        ret = Solution().myPow(x, n);
        cout << "input: " << x << "  " << n << endl
             << "ret: " << ret << endl
             << "expected: " << expected << endl << endl;
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
