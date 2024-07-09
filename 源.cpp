#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int>> dungeon = { { -2,-3,3},{ -5,-10,1},{10,30,-5} };
	int m = dungeon.size();
	int n = dungeon[0].size();
	vector<vector<int>>dp(m, vector<int>(n));
	dp[m - 1][n - 1] = max(1, -dungeon[m-1][n-1]+1);
	for (int i=m-2;i>=0;i--)
	{
		dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i][n - 1], 1);
	}
	for (int i = n - 2; i >= 0; i--)
	{
		dp[m-1][i] = max(dp[m-1][i+1] - dungeon[m - 1][i], 1);
	}
	for (int i = m - 2; i >= 0; i--)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			dp[i][j] = max(1,min(dp[i][j+1]-dungeon[i][j], dp[i + 1][j] - dungeon[i][j]));
		}
	}
	cout << dp[0][0];
	return dp[0][0];
}