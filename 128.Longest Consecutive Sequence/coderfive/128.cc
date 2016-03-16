class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
	unordered_set<int> s (nums.begin(), nums.end());
	int len = 0;
	while (!s.empty()) {
	    auto it = s.begin();
	    auto a = *it;
	    s.erase(it);
	    auto max = a+1, min = a-1;
	    while ((it = s.find(max)) != s.end()) {
		max++;
		s.erase(it);
	    }
	    while ((it = s.find(min)) != s.end()) {
		min--;
		s.erase(it);
	    }
	    if (max-min-1 > len) len = max-min-1;
	}

	return len;
    }
};
