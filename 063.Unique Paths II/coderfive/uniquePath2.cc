#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
using namespace std;

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
                return 0;
            int n = obstacleGrid.size(), m = obstacleGrid[0].size();
            for (int i = 0; i < m; i++)
                if (obstacleGrid[0][i] == 0) obstacleGrid[0][i] = -1;
                else break;
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[j][0] != 1 && obstacleGrid[j-1][0] < 0) obstacleGrid[j][0] = -1;
                for  (int i = 1; i < m; i++)
                    if (obstacleGrid[j][i] == 1) continue;
                    else {
                        if (obstacleGrid[j-1][i] < 0) obstacleGrid[j][i] += obstacleGrid[j-1][i];
                        if (obstacleGrid[j][i-1] < 0) obstacleGrid[j][i] += obstacleGrid[j][i-1];
                    }
            }

            if (obstacleGrid[n-1][m-1] == 1)
                return 0;
            return -obstacleGrid[n-1][m-1];
        }
};

/*
 * input: vector<vector<int>> ## int
 */

template<typename T>
istream& operator >> (istream& in, vector<T>& vi) {
    T val;
    vi.clear();
    while (!in.eof() && isspace(in.peek())) in.get();
    if (in.eof()) return in;
    in.get();

    while (true) {
        while (isspace(in.peek())) in.get();
        if (in.peek() == '}') {
            in.get();
            return in;
        }
        else if (in.peek() == ',') in.get();
        in >> val;
        vi.push_back(val);
    }

    return in;
}

template<typename T>
ostream& operator << (ostream& out, vector<T>& vi) {
    out << "{";
    if (vi.size() != 0)
        out << vi[0];
    for (int i = 1; i < vi.size(); i++)
        out << ", " << vi[i];
    out << "}";
    return out;
}

int main() {
    int err = 0;
    string buf;
    vector<vector<int>> vvi, saved_vvi;
    int ret, expected;

    while (true) {
        cin >> vvi;
        if (cin.eof()) break;
        cin >> buf >> expected;
        saved_vvi = vvi;
        ret = Solution().uniquePathsWithObstacles(vvi);
        if (ret != expected) {
            err = 1;
            cout << "input: " << saved_vvi << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
