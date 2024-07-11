#include<vector>
#include<iostream>
using namespace std;
int rob1(vector<int>& nums, int a, int b)
{
	int n = nums.size();
		vector<int>dp(n);
		if (b <a)
		{
			return 0;
		}
		if (a == b)
		{
			return nums[a];
		}
		dp[a] = nums[a];
		dp[a + 1] = max(nums[a], nums[a+1]);
		if (b ==1+ a)
		{
			return dp[a + 1];
		}
		if (b >= a + 2) {
			for (int i = a + 2; i <= b; i++)
			{
				dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
			}
		}
		return dp[b];
}
int main()
{
	vector<int> nums = { 1,3,1,3,100 };
	int n = nums.size();
	int ma = max(rob1(nums,1,n-1),rob1(nums,2,n-2)+nums[0]);
	cout << ma;
	return 0;
}
