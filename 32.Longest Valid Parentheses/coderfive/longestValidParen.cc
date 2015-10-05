#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        int longestValidParentheses(string s) {
            int res = 0, start = 0, paren;

            while (start < s.size()) {
                while (start < s.size() && s[start] == ')') start++;
                paren = 0;
                if (start < s.size()) {
                    int saved_start = start;
                    while (paren >= 0 && start < s.size())
                        count_paren (s[start++], paren);
                    if (paren < 0) {
                        if (start-saved_start-1 > res) res = start-saved_start-1;
                    }
                    else { // start == s.size() && paren >= 0
                        start--;
                        while (start >= saved_start) {
                            while (start >= saved_start && s[start] == '(') start--;
                            int st2 = start;
                            paren = 0;
                            while (paren <= 0 && start >= saved_start)
                                count_paren (s[start--], paren);
                            if (paren > 0) {
                                if (st2-start-1 > res) res = st2-start-1;
                            }
                            else { // start < saved_start && paren <= 0
                                if (st2-saved_start+1 > res) res = st2-saved_start+1;
                            }
                        }
                        break;
                    }
                }

            }

            return res;
        }
        void count_paren (char ch, int& paren) {
            if (ch == ')') paren--;
            else paren++;
        }
};

/*
 * input: \"[()]*\" ## int
 */

int main() {
    int err = 0, ret, expected;
    string buf, input;

    while (true) {
        cin >> input;
        if (cin.eof()) break;
        input = input.substr(1, input.size()-2);

        cin >> buf >> expected;
        ret = Solution().longestValidParentheses(input);
        if (ret != expected) {
            err = 1;
            cout << "input: \"" << input << "\"" << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
