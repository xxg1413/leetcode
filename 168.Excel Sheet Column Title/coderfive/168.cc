class Solution {
public:
    string convertToTitle(int n) {
        string res;
        int t;
        do {
            t = n%26;
            if (t == 0) {
                res.push_back('Z');
                n -= 26;
            }
            else {
                n -= t;
                res.push_back(t-1+'A');
            }
            n /= 26;
        } while (n);
        std::reverse(res.begin(), res.end());
        return res;
    }
};
