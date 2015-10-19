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
        int mySqrt(int x) {
            if (x <= 0) return 0;
            int res = 1;
            int last_res = -1;
            unsigned int nx = x;
            while (!(nx/res >= res && nx/(res+1) <= res) && res != last_res) {
                last_res = res;
                res = (res+nx/res)/2;
            }

            return res;
        }
};

/*
 * input: int ## int
 */

int main() {
    int err = 0, x, ret, expected;
    string buf;

    while (true) {
        cin >> x;
        if (cin.eof()) break;
        cin >> buf >> expected;
        ret = Solution().mySqrt(x);
        if (ret != expected) {
            err = 1;
            cout << "input: " << x << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
