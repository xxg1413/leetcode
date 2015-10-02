#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> res;
            if (n == 0) return res;
            string str (n*2, 0);
            int op = 0, i = 0;
            while (true) {
                if (op < n) {
                    if (op >= i-op) {
                        str[i++] = '(';
                        op++;
                    }
                    else {
                        while (--i >= 0 && str[i] == ')');
                        if (i < 0) break;
                        str[i++] = ')';
                        op--;
                    }
                }
                else if (op == n) {
                    fill (str.begin()+i, str.end(), ')');
                    res.push_back(str);
                    str[i-1] = ')';
                    op--;
                }
            }

            return res;
        }
};

/*
 * input: int ## vector<parens>
 * vector<parens>: {}
 *                | {\"[()]+\" [, \"[()]+\"]*}
 */

istream& operator >> (istream& in, vector<string>& vs) {
    vs.clear();
    char buf[100];
    int c;
    while (!in.eof() && isspace(in.peek())) in.get();
    if (in.eof()) return in;

    in.get();
    while (true) {
        while (isspace(in.peek())) in.get();
        if ((c = in.get()) == '}')
            return in;
        else if (c == ',')
            in.getline(buf, sizeof(buf), '"');

        in.getline(buf, sizeof(buf), '"');
        vs.push_back (string(buf));
    }

    return in;
}

ostream& operator << (ostream& out, vector<string>& vs) {
    out << "{";
    if (vs.size() != 0)
        out << "\"" << vs[0] << "\"";
    for (int i = 1; i < vs.size(); i++)
        out << ", \"" << vs[i] << "\"";
    out << "}";

    return out;
}

int main() {
    int err = 0, n;
    string buf;
    vector<string> res, ret;

    while (true) {
        cin >> n;
        if (cin.eof()) break;

        cin >> buf >> res;
        ret = Solution(). generateParenthesis(n);
        sort(ret.begin(), ret.end());
        sort(res.begin(), res.end());

        if (ret != res) {
            err = 1;
            cout << "input: " << n << "\n"
                 << "ret: " << ret << "\n"
                 << "expected: " << res << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
