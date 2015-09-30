#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) return false;
            if (x < 10) return true;
            return digit_equal (x, 1, digits(x, 1));
        }
        int digits(int x, int depth) {
            if (x < 10) return depth;
            return digits (x/10, depth+1);
        }
        bool digit_equal (int x, int lo, int hi) {
            if (lo >= hi) return true;
            return get_digit(x, lo) == get_digit(x, hi) 
                && digit_equal(x, lo+1, hi-1);
        }
        int get_digit (int x, int d) {
            if (d == 1) return x % 10;
            return get_digit (x/10, d-1);
        }
};

/*
 * input: int ## res
 */
int main() {
    string buf;
    int err = 0, res, ret, x;

    while (true) {
        cin >> x;
        if (cin.eof()) break;

        cin >> buf >> res;
        ret = Solution().isPalindrome(x);
        if (ret != res) {
            err = 1;
            cerr << "input: " << x << endl
                 << "ret: " << ret << endl
                 << "expected: " << res << endl << endl;
        }
    }

    if (err == 0)
        cout << "all tests passed!\n";

    return 0;
}
