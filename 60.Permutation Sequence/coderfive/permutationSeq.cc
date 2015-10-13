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
        string getPermutation(int n, int k) {
            string s, ret;
            vector<int> vi;
            s.push_back ('0');
            vi.push_back(1);
            for (int i = 1; i <= n; i++) {
                s.push_back (1 + s.back());
                vi.push_back (vi.back()*i);
            }
            while (s.size() != 1) {
                int idx = k/vi[s.size()-2];
                int mul = idx;
                if (k % vi[s.size()-2] != 0)
                    idx++;
                ret.push_back (s[idx]);
                k -= mul*vi[s.size()-2];
                s.erase(s.begin()+idx);
                if (k == 0) {
                    if (s.size() > 1) {
                        std::reverse (s.begin()+1, s.end());
                        ret += s.substr(1);
                    }
                    break;
                }
            }

            return ret;
        }
};

/*
 * input: int int ## \"[1-9]*\"
 */

int main() {
    int err = 0, n, k;
    string buf, expected, ret;

    while (true) {
        cin >> n;
        if (cin.eof()) break;
        cin >> k >> buf >> expected;
        expected = expected.substr(1, expected.size()-2);
        ret = Solution().getPermutation(n, k);
        if (ret != expected) {
            err = 1;
            cout << "input: " << n << "  " << k << endl
                 << "ret: \"" << ret << "\"\n"
                 << "expected: \"" << expected << "\"" << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
