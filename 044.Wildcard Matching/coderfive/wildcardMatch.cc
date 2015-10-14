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
        bool isMatch(string s, string p) {
            int start = 0, idx = 0;
            while (idx < p.size()) {
                p[start++] = p[idx++];
                if (p[idx-1] == '*')
                    while (idx < p.size() && p[idx] == '*') idx++;
            }
            p.resize(start);
            int e1 = s.size()-1, e2 = p.size() - 1;
            while (e1 >= 0 && e2 >= 0 && (s[e1] == p[e2] || p[e2] == '?')) {
                e1--;
                e2--;
            }
            s.resize(e1+1);
            p.resize(e2+1);
            if (p.size() > 0 && p.back() != '*') return false;
            if (p.size() == 0 && s.size() == 0) return true;
            e1 = e2 = 0;
            if (p[0] != '*') {
                while (e1 < s.size() && e2 < p.size() && (s[e1] == p[e2] || p[e2] == '?')) {
                    e1++;
                    e2++;
                }
                if (p[e2] != '*') return false;
            }
            e2++;
            if (p.size() == e2) return true;
            int saved_e2, saved_e1;
            while (true) {
                saved_e1 = e1;
                saved_e2 = e2;
                while (e1 < s.size() && e2 < p.size() && (s[e1] == p[e2] || p[e2] == '?')) {
                    e1++;
                    e2++;
                }
                if (p[e2] != '*') {
                    if (e1 == s.size()) return false;
                    e1 = saved_e1+1;
                    e2 = saved_e2;
                }
                else {
                    if (e2 == p.size()-1) return true;
                    e2++;
                }
            }
            return false;
        }
};

/*
 * input: \"string\" \"string\" ## true|false
 */

int main() {
    int err = 0;
    std::string buf, s, p, res;
    bool ret, expected;

    while (true) {
        std::cin >> s;
        if (std::cin.eof()) break;
        std::cin >> p >> buf >> res;
        s = s.substr(1, s.size()-2);
        p = p.substr(1, p.size()-2);
        if (res == "true") expected = true;
        else expected = false;

        ret = Solution().isMatch(s, p);

        if (ret != expected) {
            err = 1;
            cout << "input: \"" << s << "\"  \"" << p << "\"\n"
                 << "ret: " << std::boolalpha << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
