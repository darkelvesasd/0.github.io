#include<vector>
#include<iostream>
using namespace std;
int main()
{
	vector<int> nums = { 2,2,3,3,3,4 };
	int n = nums.size();
	vector<int> hash(10001);
	for (int i = 0; i <n;i++)
	{
		hash[nums[i]]+=nums[i];
	}
	vector<int>dp(10001);
	dp[0] = hash[0];
	dp[1] = max(hash[0], hash[1]);
	for (int i = 2; i < 10001; i++)
	{
		dp[i] = max(dp[i -1],dp[i-2]+hash[i]);
	}
	cout << dp[10000];
	return 0;
}
