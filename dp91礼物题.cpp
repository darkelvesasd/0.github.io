#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int>> frame = { {1, 3, 1},{1, 5, 1},{4, 2, 1} };
	int m = frame.size();
	int n = frame[0].size();
	vector<vector<int>> dp(m , vector<int>(n));
	dp[0][0] = frame[0][0];
	int i = 1;
	while (i < m)
	{
		dp[i][0] = frame[i][0]+dp[i-1][0];
		i++;
	}
	i = 1;
	while (i < n)
	{
		dp[0][i] = frame[0][i]+dp[0][i-1];
		i++;
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = max(dp[i - 1][j] , dp[i][j-1])+frame[i][j];
		}
	}
	cout << dp[m-1][n-1];
	return 0;
}
