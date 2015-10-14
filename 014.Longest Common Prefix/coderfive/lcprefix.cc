#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int i, j;
            if (strs.size() == 0) return "";
            for (i = 0; i < strs[0].size(); i++) {
                for (j = 1; j < strs.size(); j++)
                    if (strs[j][i] != strs[0][i]) break;
                if (j < strs.size()) break;
            }
            return strs[0].substr(0, i);
        }
};

/*
 * input: num \"str\"{num} ## \"res\"
 * no space in str or res
 */

int main() {
    int err = 0, num;
    vector<string> vs;
    string buf, res, ret;

    while (true) {
        vs.clear();
        cin >> num;
        if (cin.eof()) break;
        while (num--) {
            cin >> buf;
            vs.push_back(buf.substr(1, buf.size()-2));
        }
        cin >> buf >> res;
        res = res.substr(1, res.size()-2);

        ret = Solution(). longestCommonPrefix(vs);

        if (ret != res) {
            err = 1;
            cout << "input: ";
            for (auto a : vs)
                cout << "'" << a << "' ";
            cout << "\n" << "ret: '" << ret << "'\n"
                 << "expected: '" << res << "'\n\n";
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
