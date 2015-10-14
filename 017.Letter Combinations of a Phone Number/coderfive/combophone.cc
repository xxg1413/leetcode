#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        /* digits should contain only [2, 9] */
        vector<string> letterCombinations(string digits) {
            static vector<string> vs = {"abc","def","ghi","jkl","mno","pqrs","tuv", "wxyz"};
            vector<string> ret;
            if (digits.size() == 0) return ret;

            vector<int> vi (digits.size(), 0);
            string tmp = digits;
            int i = 0;
            while (true) {
                if (vi[i] == vs[digits[i]-'2'].size()) {
                    while (--i >= 0 && vi[i] == vs[digits[i]-'2'].size());
                    if (i < 0) break;
                    vi[i]++;
                }
                else {
                    tmp[i] = vs[digits[i]-'2'][vi[i]];
                    if (i == digits.size()-1) {
                        ret.push_back(tmp);
                        vi[i]++;
                    }
                    else 
                        vi[++i] = 0;
                }
            }

            return ret;
        }
};

/*
 * input: \"[2-9]*\" ## vector<string>
 * vector<string>: {}
 *                | {\"[a-z]+\" [, \"[a-z]+\"]*}
 */

istream& operator >> (istream& in, vector<string>& vs) {
    int c;
    vs.clear();
    string str;
    cin.ignore(numeric_limits<streamsize>::max(), '{');
    if (cin.eof()) return in;
    while (true) {
        while (isspace(in.peek())) in.get();
        c = in.get();
        if (c == '"') {
            str.clear();
            while ((c = in.get()) != '"')
                str.push_back(c);
            vs.push_back(str);
        }
        else if (c == '}') {
            break;
        }
    }

    return in;
}

ostream& operator << (ostream& out, vector<string>& vs) {
    out << '{';
    if (vs.size() != 0)
        out << '"' << vs[0] << '"';
    for (int i = 1; i < vs.size(); i++)
        out << ", \"" << vs[i] << '"';
    out << '}';
    return out;
}

int main() {
    int err = 0;
    string buf, digits;
    vector<string> ret, res;

    while (true) {
        cin >> digits;
        if (cin.eof()) break;
        cin >> buf >> res;
        digits = digits.substr(1, digits.size()-2);

        ret = Solution() . letterCombinations(digits);
        sort(ret.begin(), ret.end());
        sort(res.begin(), res.end());

        if (res != ret) {
            err = 1;
            cout << "input: \"" << digits << "\"\n"
                 << "ret: " << ret << "\n"
                 << "expected: " << res << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
