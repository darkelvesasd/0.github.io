class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
			int n = prices.size();
	vector<vector<int>> dp(n,vector<int>(101,-0x3f3f3f3f));
	vector<vector<int>>dp1(n,vector<int>(101,-0x3f3f3f3f));
	if (n == 1)
	{
		return 0;
	}
	dp1[0][0] = -prices[0];
	dp[0][0] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 101; j++)
		{
				dp[i][j] = dp[i - 1][j];
				dp1[i][j] = max(dp1[i-1][j],dp[i-1][j]-prices[i]);
				if (j >= 1)
				{
					dp[i][j] = max(dp[i][j], dp1[i - 1][j - 1] + prices[i]);
				}
		}
	}
	int ma = 0;
	for (int i = 1; i <=k; i++)
	{
		if (ma < dp[n-1][i])
		{
			ma = dp[n - 1][i];
		}
	}
	return ma;
    }
};
