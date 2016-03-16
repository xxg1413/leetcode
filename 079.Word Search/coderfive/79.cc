class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<char>>& b = board;
        if (b.size() == 0 || b[0].size() == 0) return false;
        for (int r = 0; r < b.size(); r++)
            for (int c = 0; c < b[0].size(); c++)
                if (exist(b, r, c, word, 0)) return true;
        return false;
    }
    bool exist(vector<vector<char>>& b, int r, int c, string& w, int i) {
        if (i == w.size()) return true;
        if (b[r][c] != w[i]) {
            return false;
        }
        if (i == w.size()-1) return true;
        char saved_c = b[r][c];
        b[r][c] = 0;
        if (r-1 >= 0 && exist(b, r-1, c, w, i+1)) return true;
        if (c-1 >= 0 && exist(b, r, c-1, w, i+1)) return true;
        if (r+1 < b.size() && exist(b, r+1, c, w, i+1)) return true;
        if (c+1 < b[0].size() && exist(b, r, c+1, w, i+1)) return true;
        b[r][c] = saved_c;
        return false;
    }
};
