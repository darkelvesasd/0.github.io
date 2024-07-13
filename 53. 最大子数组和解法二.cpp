class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		//vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	int n = nums.size();
	vector<int> dp(n);
	dp[0] = nums[0];
	int mx = dp[0];
	if (n == 1)
	{
		return dp[0];
	}
	for (int i=1;i<n;i++)
	{
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		mx = max(dp[i],mx);
	}
	return mx;
    }
};
