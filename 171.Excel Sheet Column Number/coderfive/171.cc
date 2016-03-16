class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (auto it = s.begin(); it != s.end(); it++) {
            res = res*26 + (*it-'A'+1);
        }
        return res;
    }
};
