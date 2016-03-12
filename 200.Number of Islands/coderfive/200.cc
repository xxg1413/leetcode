class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int r = 0; r < grid.size(); r++)
            for (int c = 0; c < grid[0].size(); c++)
                if (grid[r][c] == '1') {
                    res++;
                    populate_cell (grid, r, c);
                }

        return res;
    }
    void populate_cell (vector<vector<char>>& grid, int r, int c) {
        grid[r][c] = '0';
        if (r-1 >= 0 && grid[r-1][c] == '1') populate_cell (grid, r-1, c);
        if (r+1 < grid.size() && grid[r+1][c] == '1') populate_cell (grid, r+1, c);
        if (c-1 >= 0 && grid[r][c-1] == '1') populate_cell (grid, r, c-1);
        if (c+1 < grid[0].size() && grid[r][c+1] == '1') populate_cell (grid, r, c+1);
    }
};
