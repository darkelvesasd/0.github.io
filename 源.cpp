#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<int> nums = {1,2,3,1};
	int n = nums.size();
	vector<int> dp(n) ;
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	for (int i = 2; i < n; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	}
	cout << dp[n - 1];
	return 0;
}