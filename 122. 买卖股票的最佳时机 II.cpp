class Solution {
public:
    int maxProfit(vector<int>& prices) {
int n = prices.size();
	vector<int>dp(n);
	vector<int>dp1(n);
	dp[0] = 0;
	dp1[0] = -prices[0];
	if (n == 1)
	{
		return 0;
	}
	for (int i=1;i<n;i++)
	{
		dp[i] = max(dp[i-1],dp1[i-1]+prices[i]);
		dp1[i] = max(dp[i - 1] - prices[i], dp1[i - 1]);
	}
	return dp[n-1];
    }
};
