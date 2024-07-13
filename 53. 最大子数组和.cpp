class Solution {
public:
    int maxSubArray(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n);
	dp[0] = nums[0];
	if (n == 1)
	{
		return dp[0];
	}
	for (int i = 1; i < n; i++)
	{
		dp[i] = dp[i - 1] + nums[i];
	}
	int mi = 0;
	int ma = nums[0];
	for (int i = 0; i < n; i++)
	{
		ma = max(ma, dp[i] - mi);
		mi = min(mi, min(dp[i], 0));
	}
	return ma;
    }
};
