#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int m = 7, n = 3;
	vector<vector<int>> dp(m, vector<int>(n));
	int i = 0;
	while (i < m)
	{
		dp[i][0] = 1;
		i++;
	}
	i = 0;
	while (i < n)
	{
		dp[0][i] = 1;
		i++;
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[m-1][n-1];
	return 0;
}