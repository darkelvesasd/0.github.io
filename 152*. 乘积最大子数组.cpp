class Solution {
public:
    int getMaxLen(vector<int>& nums) {
	int m = nums.size();
	vector<int>dp1(m);//正数结尾最大数
	vector<int>dp2(m);//负数结尾最小数
	int ret = INT_MIN;
	if(nums[0]>0)
	dp1[0] = 1;
	if (nums[0] < 0)
		dp2[0] = 1;
    if(m==1)
    {
        return dp1[0];
    }
	for (int i = 1; i < m; i++)
	{
		if (nums[i] > 0)
		{
			dp1[i] = dp1[i - 1] + 1;
			dp2[i] = dp2[i-1]==0?0:dp2[i-1] + 1;
		}
		if(nums[i]<0)
		{
			dp1[i] = dp2[i - 1] == 0 ? 0 : dp2[i - 1] + 1;
			dp2[i] = dp1[i-1] + 1;
		}
		ret = max(dp1[i],ret);
	}
	return ret;
    }
};
