#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            s.push_back('a');
            int res = 0;
            vector<int> tab(200, 0);
            tab['I'] = 1;
            tab['V'] = 5;
            tab['X'] = 10;
            tab['L'] = 50;
            tab['C'] = 100;
            tab['D'] = 500;
            tab['M'] = 1000;
            for (int i = s.size()-2; i >= 0; i--) {
                int j = tab[s[i+1]] / tab[s[i]];
                if (j == 5 || j == 10)
                    res -= tab[s[i]];
                else
                    res += tab[s[i]];
            }

            return res;
        }
};

/*
 * input: roman_numeral ## res
 */

int main() {
    int err = 0, ret, res;
    string buf, s;

    while (true) {
        cin >> s;
        if (cin.eof()) break;

        ret = Solution(). romanToInt(s);
        cin >> buf >> res;

        if (ret != res) {
            err = 1;
            cout << "input: " << s << endl
                 << "ret: " << ret << endl
                 << "expected: " << res << endl << endl;
        }
    }

    if (err == 0)
        cout << "all tests passed!\n";

    return 0;
}
