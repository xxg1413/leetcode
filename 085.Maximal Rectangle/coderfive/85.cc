#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
using namespace std;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& vi) {
    out << "{";
    if (vi.size() != 0)
        out << vi[0];
    for (int i = 1; i < vi.size(); i++)
        out << ", " << vi[i];
    out << "}";
    return out;
}

bool err = false;

class Solution {
    public:
	int maximalRectangle(vector<vector<char>>& matrix) {
	    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
	    int rows = matrix.size(), sz = matrix[0].size();
	    int res = 0;
	    vector<int> ht(sz, 0), stack;
	    stack.reserve(sz);
	    for (int i = 0; i < rows; i++) {
		for (int j = 0; j < sz; j++) {
		    if (matrix[i][j] == '0')
			ht[j] = 0;
		    else
			ht[j]++;
		    while (stack.size() > 0 && ht[stack.back()] > ht[j]) {
			int left, height = ht[stack.back()];
			stack.pop_back();
			if (stack.size() == 0)
			    left = -1;
			else
			    left = stack.back();
			int area = height * (j-left-1);
			if (area > res) res = area;
		    }
		    stack.push_back(j);
		}
		while (stack.size() > 0) {
		    int left, height = ht[stack.back()];
		    stack.pop_back();
		    if (stack.size() == 0)
			left = -1;
		    else
			left = stack.back();
		    int area = height * (sz-left-1);
		    if (area > res) res = area;
		}
	    }
	    return res;
	}
};

void do_test (const vector<vector<char>>& h, int res) {
    vector<vector<char>> copy(h);
    int ret = Solution().maximalRectangle(copy);
    if (ret != res) {
	err = true;
	cout << "input: " << copy << "\n"
	    << "result: " << ret << ", expected: " << res << "\n\n";
    }
}

int main() {
    do_test ({{'1'}}, 1);
    do_test ({{'0','1','1','0'},{'1','1','1','1'}}, 4);
    do_test ({{'0','1','1','0'},{'1','1','1','0'}}, 4);
    do_test ({{'0','1','1','1'},{'1','1','1','1'}}, 6);
    do_test ({{'0','0','1','0'},{'1','1','1','1'}}, 4);
    if (!err)
	cout << "All tests passed!\n";

    return 0;
}
