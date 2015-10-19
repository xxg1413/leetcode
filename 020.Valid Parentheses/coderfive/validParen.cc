#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            vector<char> vc;
            for (auto a : s) {
                if (a == ')') {
                    if (vc.size() == 0 || vc.back() != '(') return false;
                    vc.pop_back();
                }
                else if (a == ']') {
                    if (vc.size() == 0 || vc.back() != '[') return false;
                    vc.pop_back();
                }
                else if (a == '}') {
                    if (vc.size() == 0 || vc.back() != '{') return false;
                    vc.pop_back();
                }
                else {
                    vc.push_back(a);
                }
            }
            if (vc.size() == 0)
                return true;
            return false;
        }
};

/*
 * input: \"[(){}[\]]*\" ## true|false
 */

int main() {
    int err = 0, ret, res;
    string buf, str;

    while (true) {
        cin >> str;
        if (cin.eof()) break;
        cin >> buf >> buf;
        str = str.substr(1, str.size()-2);
        if (buf == "true")
            res = 1;
        else 
            res = 0;
        ret = Solution() . isValid(str);
        if (res != ret) {
            err = 1;
            cout << "input: \"" << str << "\"\n"
                 << "ret: " << boolalpha << bool(ret) << "\n"
                 << "expected: " << buf << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
