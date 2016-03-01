#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
using namespace std;

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

class Solution {
	public:
		int largestRectangleArea(vector<int>& heights) {
			vector<int> idx;
			int ret = 0, i = 0, t;
			int left;
			for (; i < heights.size(); i++) {
				while (idx.size() > 0 && heights[idx.back()] > heights[i]) {
					if (idx.size() == 1)
						left = -1;
					else
						left = idx[idx.size()-2];

					t = heights[idx.back()] * (i-left-1);
					if (t > ret) ret = t;
					idx.pop_back();
				}
				idx.push_back(i);
			}
			if (idx.size() > 0) {
				int j = idx.back();
				while (idx.size() > 0) {
					if (idx.size() == 1)
						left = -1;
					else
						left = idx[idx.size()-2];
					t = heights[idx.back()] * (j-left);
					if (t > ret) ret = t;
					idx.pop_back();
				}
			}
			return ret;
		}
};
bool err = false;

void do_test (const vector<int>& h, int res) {
	vector<int> copy(h);
	int ret = Solution().largestRectangleArea(copy);
	if (ret != res) {
		err = true;
		cout << "input: " << copy << "\n"
		     << "result: " << ret << ", expected: " << res << "\n\n";
	}
}

int main() {
	do_test ({1}, 1);
	do_test ({1,2}, 2);
	do_test ({1,2,3}, 4);
	do_test ({2,1,2,1}, 4);
	do_test ({2,1,2,5}, 5);
	do_test ({5,4,1,2}, 8);
	do_test ({4,2,0,3,2,5}, 6);
	do_test ({3,6,5,7,4,8,1,0}, 20);
	do_test ({2,1,5,6,2,3}, 10);

	if (!err)
		cout << "All tests passed!\n";

	return 0;
}
