#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s = "12";
	int len = s.length();
	vector<int>dp(len);
	if (s[0] != '0')
	{
		dp[0] = 1;
	}
	if (len == 1)
	{
		return dp[0];
	}
	if (s[0] != '0' && s[1] != '0')
	{
		dp[1]++;
	}
	int t= (s[0] - '0') * 10 + s[1]-'0';
	if (t >= 10 && t <= 26)
	{
		dp[1]++;
	}
	if (len == 2)
	{
		return dp[1];
	}
	for (int i = 2; i < len; i++)
	{
		if (s[i] != '0')
		{
			dp[i] += dp[i - 1];
		}
		if ((s[i - 1] - '0') * 10 + s[i] - '0' >= 10 && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26)
		{
			dp[i] += dp[i - 2];
		}
	}
	cout << dp[len - 1];
	return 0;
}