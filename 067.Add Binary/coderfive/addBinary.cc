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
        string addBinary(string a, string b) {
            string *pls = &b, *pss = &a;
            if (a.size() > b.size()) {
                pls = &a;
                pss = &b;
            }
            string &ls = *pls, &ss = *pss;
            int i = ls.size()-1, j = ss.size()-1;
            int carry = 0;
            while (j >= 0) {
                ls[i] += carry + (ss[j]-'0');
                if (ls[i] > '1') {
                    carry = (ls[i]-'0')/2;
                    ls[i] -= carry*2;
                }
                else
                    carry = 0;
                i--; j--;
            }
            while (i >= 0 && carry > 0) {
                ls[i] += carry;
                if (ls[i] > '1') {
                    carry = (ls[i]-'0')/2;
                    ls[i] -= carry*2;
                }
                else
                    carry = 0;
                i--;
            }
            if (carry > 0)
                ls.insert (ls.begin(), '1');
            return ls;
        }
};

/*
 * input: "[01]*" "[01]*" ## "[01]*"
 */

int main() {
    int err = 0;
    string buf, a, b, ret, expected;

    while (true) {
        cin >> a;
        if (cin.eof()) break;
        cin >> b >> buf >> expected;
        ret = Solution().addBinary(a.substr(1,a.size()-2), b.substr(1,b.size()-2));
        if (ret != expected.substr(1,expected.size()-2)) {
            err = 1;
            cout << "input: " << a << " " << b << endl
                 << "ret: \"" << ret << "\"\n"
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
