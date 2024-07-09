#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int>> obstacleGrid ={{0,0,0} ,{0,1,0},{0,0,0} };
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	int i = 0;
	dp[1][0] = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (obstacleGrid[i - 1][j - 1]==1)
			{
				dp[i][j] = 0;
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	cout << dp[m][n];
	return 0;
}
