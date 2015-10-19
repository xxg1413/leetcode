#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            long long t = x;
            vector<int> v;
            if (t < 0) t = -t;
            do {
                v.push_back (t%10);
                t /= 10;
            } while (t > 0);
            for (int i = 0; i < v.size(); i++)
                t = t*10 + v[i];
            if (t > numeric_limits<int>::max())
                t = 0;
            if (x < 0)
                t = -t;
            x = t;
            return x;
        }
};

/*
 * input: int ## res
 */
int main() {
    int x, res, ret, err = 0;
    string buf;

    while (true) {
        cin >> x;
        if (cin.eof()) break;
        cin >> buf;
        cin >> res;
        ret = Solution().reverse(x);
        if (ret != res) {
            cerr << "input:        " << x << endl
                 << "ret:          " << ret << endl
                 << "expected res: " << res << endl << endl;
            err = 1;
        }
    }

    if (err == 0)
        cout << "all tests passed!\n";

    return 0;
}
