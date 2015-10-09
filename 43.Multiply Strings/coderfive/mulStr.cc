#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        string multiply(string num1, string num2) {
            reverse (num1.begin(), num1.end());
            reverse (num2.begin(), num2.end());
            string res;
            int i, j, carry;
            for (i = 0; i < num1.size(); i++) {
                carry = 0;
                for (j = 0; j < num2.size(); j++) {
                    carry += (num1[i]-'0') * (num2[j]-'0');
                    if (res.size() <= i+j) res.push_back('0');
                    res[i+j] += (carry%10);
                    carry /= 10;
                    if (res[i+j] > '9') {
                        carry++;
                        res[i+j] -= 10;
                    }
                }
                if (carry) {
                    if (res.size() <= i+j) res.push_back('0');
                    res.back() += carry;
                    if (res.back() > '9') {
                        res.push_back('1');
                        res[res.size()-2] -= 10;
                    }
                }
            }

            i = res.size()-1;
            while (i > 0 && res[i] == '0') i--;
            res.resize(i+1);
            reverse (res.begin(), res.end());
            return res;
        }
};

/*
 * input: [1-9][0-9]* [1-9][0-9]* ## [1-9][0-9]*
 */

int main() {
    int err = 0;
    string buf, num1, num2, ret, expected;

    while (true) {
        cin >> num1;
        if (cin.eof()) break;
        cin >> num2 >> buf >> expected;
        ret = Solution().multiply(num1, num2);
        if (ret != expected) {
            err = 1;
            cout << "input: " << num1 << "  " << num2 << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
