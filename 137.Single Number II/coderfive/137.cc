class Solution {
    public:
	int singleNumber (vector<int>& nums) {
	    vector<int> c (32, 0);
	    for (auto n : nums) 
		for (int i = 0; i < 32; i++)
		    if (n & (1<<i)) c[i]++;
	    int res = 0;
	    for (int i = 0; i < 32; i++)
		if (c[i] % 3 != 0) res |= (1<<i);

	    return res;
	}
};
