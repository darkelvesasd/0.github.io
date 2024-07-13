class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
	int n = nums.size();
	vector<int>dp(n) ;
	//dp[1] = dp[0] = 0;
	int sum = 0;
	for (int i = 2; i < n; i++)
	{
		if (nums[i]-nums[i-1]==nums[i - 1] - nums[i - 2])
		{
			dp[i]=++dp[i-1];
		}
		sum += dp[i];
	}
	return sum;
    }
};
