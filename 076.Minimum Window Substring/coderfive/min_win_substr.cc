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
        string minWindow(string s, string t) {
            if (t == "") return "";
            vector<int> vi(128, 0);
            for (auto c : t)
                    vi[c]--;
            int start = 0, end = 0, size = s.size(), cnt = 0;
            int rs = size, rlen = size+1;
            for (auto n : vi)
                if (n < 0) cnt++;

            while (end != size) {
                while (end != size && cnt != 0) {
                    vi[s[end]]++;
                    if (vi[s[end]] == 0) cnt--;
                    end++;
                }
                if (cnt == 0) {
                    while (start != end && cnt == 0) {
                        vi[s[start]]--;
                        if (vi[s[start]] < 0) {
                            if (end - start < rlen) {
                                rlen = end-start;
                                rs = start;
                            }
                            cnt++;
                        }
                        start++;
                    }
                }
            }

            return s.substr (rs, rlen);

        }
};

struct quoted_string {
    string str;
};
/*
 * input: quoted_string quoted_string ## quoted_string
 */

istream& operator >> (istream& in, quoted_string& qs) {
    char c;
    qs.str.clear();
    while (!in.eof() && isspace(in.peek())) in.get(c);
    if (in.eof()) return in;
    in.get(c);
    while ((in.peek() != '"')) {
        qs.str.push_back(in.peek());
        in.get(c);
    }
    in.get(c);

    return in;
}

int main() {
    bool err = false;
    string buf, s, t, expected, res;
    quoted_string qs;

    while (true) {
        cin >> qs;
        if (cin.eof()) break;
        s = qs.str;
        cin >> qs;
        t = qs.str;
        cin >> buf >> qs;
        expected = qs.str;

        res = Solution().minWindow(s, t);
        if (expected != res) {
            err = true;
            cout << "input: \"" << s << "\"  \"" << t << "\"\n"
                 << "expected: \"" << expected << "\"\n"
                 << "res: \"" << res << "\"\n\n";
        }
    }

    if (!err)
        cout << "All tests passed!\n";

    return 0;
}
