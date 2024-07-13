class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size();
	vector<int>dp(n);
	vector<int>dp1(n);
	if (n == 1)
	{
		return nums[0];
	}
	dp[0] = dp1[0] = nums[0];
	int sum = nums[0];
	int mx, mn;
	mx=mn= nums[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(nums[i], dp[i - 1] + nums[i]);
		dp1[i] = min(nums[i], dp1[i - 1] + nums[i]);
		mx = max(mx, dp[i]);
		mn = min(mn, dp1[i]);
		sum += nums[i];
	}
    	if ( sum == mn)
	{
		return mx;
	}
	return max(mx, sum - mn);
    }
};
