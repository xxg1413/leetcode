#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            return tryMatch (s, 0, p, 0);
        }
        bool tryMatch(const string &s, int pos, const string &p, int pos2) {
            if (pos == s.size() && pos2 == p.size()) return true;
            if (pos2 >= p.size() && pos < s.size()) return false;
            if (pos2+1 < p.size()) {
                if (p[pos2+1] == '*') {
                    /* '?*' match nothing */
                    if (tryMatch (s, pos, p, pos2+2)) return true;
                    /* '?*' match one char */
                    if (pos < s.size() && (p[pos2] == '.' || p[pos2] == s[pos]))
                        return tryMatch (s, pos+1, p, pos2);
                }
                else {
                    if (pos >= s.size()) return false;
                    if (p[pos2] != '.' && s[pos] != p[pos2]) return false;
                    return tryMatch(s, pos+1, p, pos2+1);
                }
            }
            else { /* last char */
                if (pos == s.size()-1 && 
                        (p[pos2] == '.' || p[pos2] == s[pos]))
                    return true;
                return false;
            }
            return false;
        }
};

/*
 * input: (\"[^"]*\"){2} ## 1|0 1-->true, 0-->false
 */

int get_string (string &s) {
    char c;
    cin >> s;
    if (cin.eof()) return 1;
    while (s.size() < 2 || s.back() != '"') {
        cin >> c;
        s.push_back(c);
    }
    s = s.substr(1, s.size()-2);
    return 0;
}

int main() {
    string s, p, buf;
    int err = 0, res, ret;

    while (true) {
        if (get_string(s)) break;
        get_string(p);
        cin >> buf;
        cin >> res;
        ret = Solution().isMatch(s, p);
        if ((ret && !res) || (!ret && res)) {
            cerr << "input: '" << s << "' '" << p << "'" << endl
                 << "ret: " << ret << endl
                 << "expected res: " << res << endl << endl;
            err = 1;
        }
    }

    if (err == 0)
        cout << "all tests passed!\n";

    return 0;
}
