class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
	if (k == 0) return 0;
	int res = 0;
	auto sz = prices.size();
	if (sz <= 1) return 0;
	if (k >= sz/2) {
	    for (int i = 1; i < sz; i++)
		if (prices[i] > prices[i-1]) res += prices[i]-prices[i-1];
	    return res;
	}
	vector<int> buy (k+1, -prices[0]);
	vector<int> profits (k+1, 0);
	for (int i = 1; i < sz; i++) {
	    for (int j = 1; j <= k; j++) {
		int n = prices[i];
		if (buy[j] < profits[j-1]-n) buy[j] = profits[j-1]-n;
		if (profits[j] < n+buy[j]) profits[j] = n+buy[j];
	    }
	}
	return profits.back();
    }
};
