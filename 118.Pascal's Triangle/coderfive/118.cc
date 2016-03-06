class Solution {
public:
    vector<vector<int>> generate(int numRows) {
	vector<vector<int>> res;
	if (numRows <= 0) return res;
	res.push_back(vector<int>({1}));
	for (int i = 1; i < numRows; i++) {
	    res.push_back(vector<int>({1}));
	    vector<int>& v = res.back();
	    vector<int>& last = res[res.size()-2];
	    for (int j = 1; j < last.size(); j++)
		v.push_back(last[j-1]+last[j]);
	    v.push_back(1);
	}

	return res;
    }
};
