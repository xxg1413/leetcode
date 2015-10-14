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
        int lengthOfLastWord(string s) {
            int i = s.size()-1, ret = 0;
            while (i >= 0 && s[i] == ' ') i--;
            while (i >= 0 && s[i] != ' ') {
                i--;
                ret++;
            }
            return ret;
        }
};

/*
 * input: \"[a-zA-Z ]*\" ## int
 */

int main() {
    int err = 0, ret, expected;
    string buf, s, saved_s;

    while (true) {
        s.clear();
        while (!cin.eof() && isspace(cin.peek())) cin.get();
        if (cin.eof()) break;
        cin.get();
        while (cin.peek() != '"') s.push_back(cin.get());
        cin.get();
        cin >> buf >> expected;
        ret = Solution().lengthOfLastWord(s);
        if (ret != expected) {
            err = 1;
            cout << "input: \"" << s << "\"\n"
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
