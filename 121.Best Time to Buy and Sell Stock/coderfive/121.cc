class Solution {
public:
    int maxProfit(vector<int>& prices) {
	int res = 0;
	if (prices.size() == 0) return 0;
	int min = prices[0];
	for (int i = 1; i < prices.size(); i++) {
	    if (prices[i] < min) min = prices[i];
	    else if (prices[i] - min > res) res = prices[i] - min;
	}

	return res;
    }
};
