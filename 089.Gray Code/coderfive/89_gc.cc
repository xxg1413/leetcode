#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
using namespace std;

string to_binary(int);
template<typename T>
ostream& operator << (ostream& out, vector<T>& vi) {
    out << "{";
    if (vi.size() != 0)
        out << to_binary(vi[0]);
    for (int i = 1; i < vi.size(); i++)
        out << ", " << to_binary(vi[i]);
    out << "}";
    return out;
}

bool err = false;
class Solution {
public:
    vector<int> grayCode(int n) {
	    vector<int> vi {0};
	    for (int i = 0; i < n; i++)
		    for (int it = vi.size()-1; it >= 0; it--)
			    vi.push_back(vi[it] + (1 << i));
	    return vi;
    }
};

string to_binary(int n) {
	string s;
	while (n) {
		if (n & 1) s.push_back('1');
		else s.push_back('0');
	}
	reverse(s.begin(), s.end());
	return s;
}


void do_test (int n) {
	static int counter = 0;
	vector<int> ret = Solution().grayCode(n);
	counter++;
	for (int i = 1; i < ret.size(); i++) {
		int diff = ret[i] ^ ret[i-1];
		while (diff && (0 == (diff & 1))) diff >>= 1;
		if (diff != 1) {
			err = true;
			cout << "#" << counter << "\n";
			cout << "input: " << n << "\n"
			     << "expected: " << ret << "\n\n";
			break;
		}
	}
}

int main() {
	do_test(1);
	do_test(2);
	do_test(3);
	do_test(4);
	if (!err)
		cout << "All tests passed!\n";

	return 0;
}
