#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos (200, 0), appeared(200, 0);
        int res = 0, len, cur_pos = -1;
        unsigned int idx;
        int i;
        for (i = 0; i < s.size(); i++) {
            idx = static_cast<unsigned int> (s[i]);
            if (++appeared[idx] > 1) {
                if (pos[idx] > cur_pos) {
                    len = i-cur_pos-1; 
                    cur_pos = pos[idx];
                    if (res < i - cur_pos) res = i-cur_pos;
                    if (res < len) res = len;
                }
                appeared[idx] = 1;
            }
            pos[idx] = i;
        }
        if (res < i - cur_pos - 1) res = i-cur_pos-1;

        return res;
    }
};

/*
 * input: \"[a-zA-Z]*\"  ## notes to be ignored
 */
int main() {
    string buf;
    while (true) {
        cin >> buf;
        if (cin.eof()) return 0;
        cout << Solution().lengthOfLongestSubstring (buf.substr(1, buf.size()-2)) << endl;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
