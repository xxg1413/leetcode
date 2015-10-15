#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
#include <iterator>
using namespace std;

/*
 * assuming there is no empty word in words.
 */
class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> res;
            int i = 0, j, len, sp, extra_sp;
            for (; i < words.size(); ) {
                j = i+1;
                len = words[i].size();
                while (j < words.size() && (len+words[j].size()+j-i) <= maxWidth)
                    len += words[j++].size();
                if (j == words.size()) {
                    res.push_back (words[i++]);
                    while (i != j) {
                        res.back() += ' ' + words[i++];
                    }
                    if (res.back().size() != maxWidth)
                        std::fill_n (std::back_inserter(res.back()), maxWidth-res.back().size(), ' ');
                    return res;
                }
                res.push_back (words[i]);
                if (j == i+1) {
                    std::fill_n (std::back_inserter(res.back()), maxWidth-len, ' ');
                }
                else {
                    sp = (maxWidth-len)/(j-i-1);
                    extra_sp = maxWidth-sp*(j-i-1)-len;
                    i++;
                    string &s = res.back();
                    while (i != j) {
                        std::fill_n (std::back_inserter(s), sp, ' ');
                        if (extra_sp) {
                            s.push_back(' ');
                            extra_sp--;
                        }
                        s += words[i++];
                    }
                }
                i = j;
            }

            return res;
        }
};

/*
 * input: vector<string> int ## vector<string>
 * string should be quoted and contains no white space.
 */

istream& operator >> (istream& in, vector<string>& vi) {
    string val;
    vi.clear();
    while (!in.eof() && isspace(in.peek())) in.get();
    if (in.eof()) return in;
    in.get();
    char c;

    while (true) {
        while (isspace(in.peek())) in.get();
        if (in.peek() == '}') {
            in.get();
            return in;
        }
        else if (in.peek() == ',') in.get();
        while (isspace(in.get()));
        val.clear();
        while ((c = in.get()) != '"') val.push_back (c);
        vi.push_back(val);
    }

    return in;
}

ostream& operator << (ostream& out, vector<string>& vi) {
    out << "{";
    if (vi.size() != 0)
        out << '"' << vi[0] << '"';
    for (int i = 1; i < vi.size(); i++)
        out << ", \"" << vi[i] << '"';
    out << "}";
    return out;
}

int main() {
    int err = 0, maxWidth;
    string buf, s;
    vector<string> vs, expected, ret;

    while (true) {
        cin >> vs;
        if (cin.eof()) break;
        cin >> maxWidth >> buf >> expected;
        ret = Solution().fullJustify(vs, maxWidth);
        if (ret != expected) {
            err = 1;
            cout << "input: " << vs << " " << maxWidth << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
