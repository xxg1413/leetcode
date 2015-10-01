#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int res = 0, t;
        if (size < 2) return res;
        res = min (height.back(), height[0]) * (size-1);
        
        int start = 0, end = size-1;
        for (; start < end; start++) {
            for (; start < end && height[start] >= height[end]; end--) {
                t = height[end] * (end-start);
                if (t > res) res = t;
            }
            if (start < end) {
                t = min (height[start], height[end]) * (end-start);
                if (t > res) res = t;
            }
        }

        return res;
    }
};

/*
 * input: int int{2,}  ## res
 */
int main() {
    int h, err = 0, num, ret, res;
    vector<int> v;
    string buf;

    while (true) {
        v.clear();
        cin >> num;
        if (cin.eof()) break;
        while (num--) {
            cin >> h;
            v.push_back(h);
        }
        ret = Solution().maxArea(v);
        cin >> buf >> res;
        if (ret != res) {
            err = 1;
            cout << "input: ";
            for (auto a : v)
                cout << a << " ";
            cout << "\n" << "ret: " << ret << "\n"
                 << "expected: " << res << endl << endl;
        }
    }

    if (err == 0)
        cout << "all tests passed!\n";

    return 0;
}
