class Solution {
public:
    vector<int> getRow(int rowIndex) {
	vector<int> v;
	if (rowIndex < 0) return v;
	v.push_back(1);
	for (int i = 0; i < rowIndex; i++) {
	    for (int j = v.size()-1; j > 0; j--)
		v[j] += v[j-1];
	    v.push_back(1);
	}

	return v;
    }
};
