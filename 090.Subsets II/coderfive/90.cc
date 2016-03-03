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
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			std::sort(nums.begin(), nums.end());
			vector<vector<int>> res (1, vector<int>());
			int pos = 0, sz;
			for (int i = 0; i < nums.size(); i++) {
				sz = res.size();
				if (i > 0 && nums[i] != nums[i-1]) pos = 0;
				while (pos < sz) {
					res.push_back(res[pos]);
					res.back().push_back(nums[i]);
					pos++;
				}
			}
			return res;
		}
};

void do_test (const vector<int>& v) {
	vector<int> copy(v);
	static int counter = 0;
	auto ret = Solution().subsetsWithDup(copy);
	counter++;
	vector<vector<int>> expected (1, vector<int>());
	std::sort(copy.begin(), copy.end());
	for (int i = 0; i < copy.size(); i++) {
		int esize = expected.size();
		for (int j = 0; j < esize; j++) {
			expected.push_back(expected[j]);
			expected.back().push_back(copy[i]);
		}
	}
	std::sort(expected.begin(), expected.end());
	expected.resize(std::unique(expected.begin(), expected.end()) - expected.begin());
	std::sort(ret.begin(), ret.end());
	if (ret != expected) {
		err = true;
		cout << "#" << counter << "\n";
		cout << "input: " << v << "\n"
		     << "expected: " << expected << "\n"
		     << "got: " << ret << "\n\n";
	}
}

int main() {
	do_test ({});
	do_test ({1});
	do_test ({1,1});
	do_test ({1,2,2});
	do_test ({1,2,3});
	do_test ({1,2,2,2,3});
	do_test ({1,2,2,3,3});
	do_test ({1,2,2,4,3,3});
	if (!err)
		cout << "All tests passed!\n";

	return 0;
}
