class Solution {
public:
    int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<vector<int>> dp(n, vector<int>(3,-0x3f3f3f3f));
	vector<vector<int>>dp1(n, vector<int>(3, -0x3f3f3f3f));
	dp[0][0] = 0;
	dp1[0][0] = -prices[0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dp[i][j] = dp[i - 1][j];
			dp1[i][j] = max(dp[i - 1][j] - prices[i], dp1[i - 1][j]);
			if (j >= 1)
			{
				dp[i][j] = max(dp[i - 1][j], dp1[i-1][j-1]+prices[i]);
			}
		}
	}
	int m = 0;
	for (int i = 0; i < 3; i++)
	{
		if (m < dp[n - 1][i])
		{
			m = dp[n - 1][i];
		}
	}
	return m;
    }
};
