#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        int divide(int dividend, int divisor) {
            if (divisor == 0) return numeric_limits<int>::max();
            long long res = 0;
            long long di = dividend, ds = divisor;
            if (di < 0) di = -di;
            if (ds < 0) ds = -ds;
            while (ds <= di) {
                int i = 1;
                while ((di >> i) >= ds) i++;
                res += (static_cast<long long>(1))<<(i-1);
                di -= ds << (i-1);
            }
            long long ma = numeric_limits<int>::max();
            long long mi = numeric_limits<int>::min();
            if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
                res = -res;
            if (res > ma || res < mi)
                return numeric_limits<int>::max();
            return static_cast<int> (res);
        }
};

/*
 * input: int int ## int
 */

int main() {
    int err = 0, di, ds, ret, expected;
    string buf;

    while (true) {
        cin >> di;
        if (cin.eof()) break;
        cin >> ds >> buf >> expected;

        ret = Solution(). divide(di, ds);
        if (ret != expected) {
            err = 1;
            cout << "input: " << di << " " << ds << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
