class Solution {
    public:
	void solve (vector<vector<char>>& board) {
	    if (board.size() == 0) return;
	    int rows = board.size(), cols = board[0].size();
	    for (int i = 0; i < rows; i++) {
		fill_a(board, i, 0);
		fill_a(board, i, cols-1);
	    }
	    for (int i = 0; i < cols; i++) {
		fill_a(board, 0, i);
		fill_a(board, rows-1, i);
	    }
	    // replace 'O'
	    for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
		    if (board[i][j] == 'O') board[i][j] = 'X';
		    else if (board[i][j] == 'a') board[i][j] = 'O';
		}
	}
	void fill_a (vector<vector<char>>& b, int r, int c) {
	    if (b[r][c] != 'O') return;
	    vector<pair<int,int>> vp;
	    vp.push_back(std::make_pair(r,c));
	    pair<int,int>p;
	    while (!vp.empty()) {
		p = vp.back();
		vp.pop_back();
		r = p.first;
		c = p.second;
		b[r][c] = 'a';
		if (r > 0 && b[r-1][c] == 'O') vp.push_back(make_pair(r-1,c));
		if (r+1 < b.size() && b[r+1][c] == 'O') vp.push_back(make_pair(r+1,c));
		if (c > 0 && b[r][c-1] == 'O') vp.push_back(make_pair(r,c-1));
		if (c+1 < b[0].size() && b[r][c+1] == 'O') vp.push_back(make_pair(r,c+1));
	    }
	}
};
