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
	int minDistance(string word1, string word2) {
	    vector<int> v;
	    for (int i = 0; i <= word1.size(); i++)
		v.push_back(i);
	    for (int j = 0; j < word2.size(); j++) {
		int t = v[0];
		v[0] = j+1;
		for (int i = 0; i < word1.size(); i++) {
		    int cost;
		    if (word2[j] == word1[i])
			cost = t;
		    else 
			cost = min(t, min(v[i], v[i+1]))+1;
		    t = v[i+1];
		    v[i+1] = cost;
		}
	    }
	    return v.back();
	}
};

bool err = false;
void do_test (const string& s1, const string& s2, int expected) {
    static int counter = 0;
    counter++;
    string ns1(s1), ns2(s2);
    int ret = Solution().minDistance(ns1, ns2);
    if (ret != expected) {
	err = true;
	cout << "#" << counter << "\n"
	    << "input: '" << s1 << "', '" << s2 << "'\n"
	    << "expected: " << expected << "\n"
	    << "ret: " << ret << "\n\n";
    }
}

int main() {
    do_test ("", "", 0);
    do_test ("a", "", 1);
    do_test ("", "a", 1);
    do_test ("a", "b", 1);
    do_test ("ab", "b", 1);
    do_test ("ba", "b", 1);

    if (!err)
        cout << "All tests passed!\n";

    return 0;
}
