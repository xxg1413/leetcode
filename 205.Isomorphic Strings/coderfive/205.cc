class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> mp (200, 0);
        vector<bool> taken (200, false);
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] == 0) {
                if (taken[t[i]]) return false;
                mp[s[i]] = t[i];
                taken[t[i]] = true;
            }
            else if (mp[s[i]] != t[i]) return false;
        }
        return true;
    }
};
