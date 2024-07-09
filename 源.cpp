#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>>dp(m, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		dp[0][i] = matrix[0][i];
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = min(min(dp[i - 1][max(0, j - 1)], dp[i - 1][j]), dp[i - 1][min(n - 1, j + 1)]) + matrix[i][j];
		}
	}
	int minu= (int)INT_MAX;
	for (int i = 0; i < n; i++)
	{
		minu = min(minu, dp[m - 1][i]);
	}
	cout << minu;
	return 0;
}