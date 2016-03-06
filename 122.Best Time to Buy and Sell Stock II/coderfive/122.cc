class Solution {
public:
    int maxProfit(vector<int>& prices) {
	int res = 0, t;
	if (prices.size() == 0) return 0;
	for (int i = 1; i < prices.size(); i++)
	    if ((t = prices[i] - prices[i-1]) > 0)
		res += t;

	return res;
    }
};
