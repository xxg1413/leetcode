class Solution {
public:
    int maxProfit(vector<int>& prices) {
	vector<int> v (prices.size(), 0);
	int res = 0;
	if (prices.size() == 0) return 0;
	int p = prices[0];
	for (int i = 1; i < prices.size(); i++) {
	    if (prices[i] < p) 
		p = prices[i];
	    v[i] = std::max(v[i-1], prices[i]-p);
	}

	p = prices.back();
	for (int i = prices.size()-2; i >= 0; i--) {
	    if (prices[i] > p)
		p = prices[i];
	    v[i] += std::max(0, p-prices[i]);
	    if (v[i] > res) res = v[i];
	}

	return res;
    }
};
