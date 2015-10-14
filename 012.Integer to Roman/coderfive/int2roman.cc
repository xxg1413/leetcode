#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        /* num is within [1, 3999] */
        string intToRoman(int num) {
            static char tab[][4] = {
                "IVX", "XLC", "CDM", "M"
            };
            string res, tmp;
            for (int i = 0; num != 0; i++) {
                int t = num % 10;
                num /= 10;
                tmp = "";
                if (t < 4) {
                    for (int k = 0; k < t; k++)
                        tmp.push_back(tab[i][0]);
                }
                else if (t == 4) {
                    tmp.push_back(tab[i][0]);
                    tmp.push_back(tab[i][1]);
                }
                else if (t < 9) {
                    tmp.push_back(tab[i][1]);
                    for (int k = 5; k < t; k++)
                        tmp.push_back(tab[i][0]);
                }
                else if (t == 9) {
                    tmp.push_back(tab[i][0]);
                    tmp.push_back(tab[i][2]);
                }
                res = tmp+res;
            }

            return res;
        }
};

/*
 * input: int ## res
 */

int main() {
    int err = 0, num;
    string buf, res, ret;

    while (true) {
        cin >> num;
        if (cin.eof()) break;

        cin >> buf >> res;
        ret = Solution().intToRoman(num);
        if (res != ret) {
            err = 1;
            cout << "input: " << num << endl
                 << "ret: " << ret << endl
                 << "expected: " << res << endl << endl;
        }
    }

    if (err == 0)
        cout << "all tests passed!\n";

    return 0;
}
