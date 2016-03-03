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

class Solution {
    public:
	bool is_valid (const string& s, int first, int last) {
	    if (last-first > 3 || last <= first) return false;
	    if (s[first] == '0' && last - first != 1) return false;
	    int n = 0;
	    while (first < last) n = n*10 +  s[first++] - '0';
	    return n < 256;
	}
	vector<string> restoreIpAddresses(string s) {
	    vector<string> vs;
	    int i[5], j = 1, sz = s.size();
	    i[0] = 0, i[1] = 1;
	    i[4] = sz;
	    while (true) {
		if (j == 4) {
		    if (is_valid (s, i[3], sz)) {
			vs.push_back("");
			string& rs = vs.back();
			rs.resize(sz+3);
			auto it = rs.begin();
			for (auto k = 0; k < 3; k++) {
			    copy (s.begin()+i[k], s.begin()+i[k+1], it);
			    it = rs.begin() + i[k+1]+k;
			    *it = '.';
			    it++;
			}
			copy (s.begin()+i[3], s.begin()+sz, rs.begin() + i[3] + 3);
		    }
		    j--;
		    i[j]++;
		}
		while (!is_valid (s, i[j-1], i[j])) {
		    j--;
		    if (j == 0) return vs;
		    i[j]++;
		}
		i[j+1] = i[j]+1;
		j++;
	    }

	    return vs;
	}
};

bool err = false;

void do_test (const string& s, const vector<string>& expected) {
    string ns(s);
    auto ret = Solution().restoreIpAddresses(ns);
    std::sort(ret.begin(), ret.end());
    auto ve(expected);
    std::sort(ve.begin(), ve.end());
    if (ret != ve) {
	err = true;
	cout << "input: '" << s << "'\n"
	    << "result: " << ret << ", expected: " << expected << "\n\n";
    }
}

int main() {
    do_test ("25525511135", {"255.255.11.135", "255.255.111.35"});
    do_test ("999314", {"9.9.93.14","9.99.3.14","9.99.31.4","99.9.3.14","99.9.31.4","99.93.1.4"});
    do_test ("19234", {"1.9.2.34","1.9.23.4","1.92.3.4","19.2.3.4"});

    if (!err)
	cout << "All tests passed!\n";

    return 0;
}
