#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
using namespace std;

/*
 * num1: [0-9]+
 * num2: [0-9]*
 * number: (-|+)(num1|.num2|0.num2|num1.num2)(e(+|-)num1)
 */
class Solution {
public:
    bool isNumber(string s) {
        int i = s.size()-1;
        bool prefix = false;
        while (i >= 0 && s[i] == ' ') i--;
        s.resize (i+1);
        i = 0;
        while (i < s.size() && s[i] == ' ') i++;
        if (i == s.size()) return false;
        if (s[i] == '-' || s[i] == '+') i++;
        if (s[i] != '.') {
            if (false == expect_num1 (s, i)) return false;
            prefix = true;
        }
        
        if (i >= s.size()) return true;
        if (s[i] == '.') {
            if (i == s.size()-1 && (i == 0 || s[i-1] == ' ')) return false;
            if (prefix)
                expect_num2(s, ++i);
            else {
                if (expect_num1 (s, ++i) == false) return false;
            }
        }
        if (i != s.size()) {
            if (!expect_pow (s, i)) return false;
        }
        return i == s.size();
    }
    bool expect_pow (string& s, int& i) {
        if (i >= s.size()-1 || s[i++] != 'e') return false;
        if (s[i] == '-' || s[i] == '+') i++;
        return expect_num1 (s, i);
    }
    bool expect_num1 (string& s, int& i) {
        if (i == s.size()) return false;
        int si = i;
        while (i < s.size() && std::isdigit(s[i])) i++;
        return si != i;
    }
    void expect_num2 (string& s, int& i) {
        while (i < s.size() && std::isdigit(s[i])) i++;
    }
};

/*
 * input: \"string\" ## true|false
 */

int main() {
    int err = 0;
    string buf, input;
    bool ret, expected;

    while (true) {
        cin >> input;
        if (cin.eof()) break;
        if (input.size() == 1 || input.back() != '"') {
            while ('"' != cin.peek()) input.push_back (cin.get());
            input.push_back (cin.get());
        }
        cin >> buf >> buf;
        if (buf == "false") expected = false;
        else expected = true;
        ret = Solution().isNumber(input.substr(1,input.size()-2));
        if (ret != expected) {
            err = 1;
            cout << "input: " << input << endl
                 << "ret: " << std::boolalpha << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
