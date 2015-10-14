#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

/*
 * kmp algorithm
 */
class Solution {
    public:
        int strStr(string haystack, string needle) {
            if (needle.size() > haystack.size()) return -1;
            vector<int> vi (needle.size(), -1);
            int i, j;
            for (i = 1, j = 0; i < needle.size(); ) {
                if (vi[i] < 0)
                    vi[i] = j;
                if (needle[i] == needle[j]) {
                    i++;
                    j++;
                }
                else {
                    j = vi[j];
                    if (j < 0) {
                        i++;
                        j = 0;
                    }
                }
            }

            for (i = j = 0; j < haystack.size() && i < needle.size(); ) {
                if (needle[i] == haystack[j]) {
                    i++;
                    j++;
                }
                else {
                    i = vi[i];
                    if (i < 0) {
                        i = 0;
                        j++;
                    }
                }
            }
            if (i == needle.size()) return j-i;

            return -1;
        }
};

/*
 * input: \"string\"{2} ## int
 */

int main() {
    int err = 0, ret, expected;
    string buf, hay, ned;

    while (true) {
        cin >> hay;
        if (cin.eof()) break;
        cin >> ned >> buf >> expected;
        hay = hay.substr(1, hay.size()-2);
        ned = ned.substr(1, ned.size()-2);

        ret = Solution().strStr(hay, ned);
        if (ret != expected) {
            err = 1;
            cout << "input: \"" << hay << "\"  \"" << ned << "\"" << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
