#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            string res, res2;
            if (n <= 0) return string("");

            res.push_back('1');
            while (n-- > 1) {
                int i = 0, j;
                while (i < res.size()) {
                    j = i;
                    while (j < res.size() && res[i] == res[j]) j++;
                    res2 += to_string(j-i);
                    res2.push_back(res[i]);
                    i = j;
                }
                swap (res, res2);
                res2.clear();
            }

            return res;
        }
};

/*
 * input: int ## \"[0-9]*\"
 */

int main() {
    int err = 0, n;
    string buf, expected, ret;

    while (true) {
        cin >> n;
        if (cin.eof()) break;
        cin >> buf >> expected;
        expected = expected.substr(1, expected.size()-2);
        ret = Solution().countAndSay(n);
        if (ret != expected) {
            err = 1;
            cout << "input: " << n << endl
                 << "ret: \"" << ret << "\"\n"
                 << "expected: \"" << expected << "\"\n" << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
