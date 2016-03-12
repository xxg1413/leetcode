class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visited (numCourses, 0);
        vector<vector<int>> g (numCourses, vector<int>());
        for (auto& p : prerequisites)
            g[p.first].push_back(p.second);
        for (int i = 0; i < numCourses; i++)
            if (visited[i] == 0) {
                if (!dfs(g, visited, i))
                    return false;
            }
        return true;
    }
    bool dfs (vector<vector<int>>& g, vector<int>& v, int i) {
        v[i] = 1;
        for (int j = 0; j < g[i].size(); j++)
            if (v[g[i][j]] == 2) continue;
            else if (v[g[i][j]] == 1) return false;
            else if (!dfs(g, v, g[i][j])) return false;
        v[i] = 2;
        return true;
    }
};
