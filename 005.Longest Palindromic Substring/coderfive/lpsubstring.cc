#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

/* 
 * n <= 1000
 * O(n^2)
 */
class Solution {
    public:
        string longestPalindrome(string s) {
            int pos = 0, len = 0;
            int size = s.size();
            int i, j, t;
            /* centered on a char */
            for (i = 0; i < size; i++) {
                for (j = 0; i-j >= 0 && i+j < size; j++)
                    if (s[i-j] != s[i+j])
                        break;
                t = j*2-1;
                if (len < t) {
                    len = t;
                    pos = i-j+1;
                }
            }
            /* centered between chars */
            for (i = 1; i < size; i++) {
                for (j = 1; i-j >= 0 && i+j-1 < size; j++)
                    if (s[i-j] != s[i+j-1])
                        break;
                t = j*2-2;
                if (len < t) {
                    len = t;
                    pos = i-j+1;
                }
            }

            return s.substr(pos, len);
        }
};

/*
 * input: \"[a-zA-Z]*\"  ## \"result\"
 */
int main() {
    string s, res, ret;
    int err = 0;
    while (true) {
        cin >> s;
        if (cin.eof()) break;
        s = s.substr(1, s.size()-2);
        ret = Solution() . longestPalindrome (s);
        cin >> res;
        cin >> res;
        res = res.substr(1, res.size()-2);
        if (ret != res) {
            cerr << "input: '" << s << "'\n" 
                 << "ret: '" << ret << "'\n"
                 << "expected: '" << res << "'\n\n";
            err = 1;
        }
    }
    if (err == 0)
        cout << "all tests passed!\n";

    return 0;
}
