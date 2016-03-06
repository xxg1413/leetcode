class Solution {
public:
    int maxProfit(vector<int>& prices) {
	if (prices.size() == 0) return 0;
	int a[4] {-prices[0], 0, -prices[0], 0};

	for (int i = 1; i < prices.size(); i++) {
	    if (a[0] < -prices[i]) a[0] = -prices[i];
	    if (a[1] < prices[i] + a[0]) a[1] = prices[i]+a[0];
	    if (a[2] < -prices[i] + a[1]) a[2] = -prices[i] + a[1];
	    if (a[3] < prices[i] + a[2]) a[3] = prices[i] + a[2];
	}

	return a[3];
    }
};

