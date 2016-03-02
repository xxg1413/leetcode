#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
using namespace std;


bool err = false;
class Solution {
	public:
		int numDecodings(string s) {
			if (s.size() == 0) return 0;
			int sz = s.size();
			vector<int> v (s.size()+1, 0);
			v[sz-1] = 1;
			v[sz] = 1;
			if (!(s.back() <= '9' && s.back() >= '1')) v[sz-1] = 0;
			for (int i = sz-2; i >= 0; i--) {
				if (s[i] <= '9' && s[i] >= '1')
					v[i] = v[i+1];
				if (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
					v[i] += v[i+2];
			}
			return v[0];
		}
};

void do_test (const string& s, int expected) {
	static int counter = 0;
	auto ret = Solution().numDecodings(s);
	counter++;
	if (ret != expected) {
		err = true;
		cout << "#" << counter << "\n";
		cout << "input: '" << s << "'\n"
		     << "expected: " << expected << "\n"
		     << "got: " << ret << "\n\n";
	}
}

int main() {
	do_test ("", 0);
	do_test ("0", 0);
	do_test ("01", 0);
	do_test ("3", 1);
	do_test ("36", 1);
	do_test ("26", 2);
	if (!err)
		cout << "All tests passed!\n";

	return 0;
}
