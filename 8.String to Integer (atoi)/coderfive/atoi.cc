#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        int myAtoi(string str) {
            int i = 0;
            while (i < str.size() && isspace(str[i])) i++;
            if (i >= str.size()) return 0;

            long long int_max = numeric_limits<int>::max();
            long long int_min = numeric_limits<int>::min();
            int_min = -int_min;
            long long res = 0;
            int sign = 1;
            if (str[i] == '-') {
                sign = -1;
                i++;
            }
            else if (str[i] == '+') 
                i++;
            if (i >= str.size() || !isdigit(str[i]))
                return 0;

            while (i < str.size() && isdigit(str[i])) {
                res = res*10 + (str[i]-'0');
                if (sign == 1 && res > int_max)
                    return int_max;
                if(sign == -1 && res > int_min)
                    return -int_min;
                i++;
            }

            if (sign == -1) res = -res;
            return static_cast<int>(res);

        }
};

/*
 * input: \"[^"]*\" ## res
 */

int main() {
    string str, buf;
    int err = 0, ret, res;
    char c;

    while (true) {
        cin >> str;
        if (cin.eof()) break;
        if (str.size() < 2 || str.back() != '"') {
            while (true) {
                cin >> c;
                str.push_back(c);
                if (c == '"') break;
            }
        }

        str = str.substr(1, str.size()-2);
        ret = Solution().myAtoi(str);
        cin >> buf >> res;
        if (res != ret) {
            err = 1;
            cerr << "input: '" << str << "'\n"
                 << "ret: " << ret << endl
                 << "expected: " << res << endl << endl;
        }
    }

    if (err == 0)
        cout << "all tests passed!\n";

    return 0;
}
