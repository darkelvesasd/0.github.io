#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<int> nums = { 1,2 };
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    vector<int>dp(n);
    dp[0] = nums[0];
    if (n == 1)
    {
        return dp[0];
    }
    dp[1] = max(dp[1], dp[0]);
    if (n == 2)
    {
        return dp[1];
    }
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
}