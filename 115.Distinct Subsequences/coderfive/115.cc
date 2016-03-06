#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
	if (s.size() == 0 || t.size() == 0) return 0;
	if (t.size() > s.size()) return 0;
	vector<int> v (t.size(), 0);
	map<char, vector<int>> mp;
	for (int i = 0; i < t.size(); i++)
	    mp[t[i]].push_back(i);
	for (auto a : s) {
	    vector<int>& idx = mp[a];
	    for (auto it = idx.rbegin(); it != idx.rend(); it++)
		if (*it == 0) v[*it]++;
		else v[*it] += v[*it-1];
	}

	return v.back();
    }
};

int main() {
    std::cout << Solution().numDistinct("ccc", "c") << std::endl;
    std::cout << Solution().numDistinct("ccc", "cc") << std::endl;

    return 0;
}
