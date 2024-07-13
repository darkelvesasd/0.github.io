class Solution {
public:
    int maxProduct(vector<int>& nums) {
	int n = nums.size();
	vector<double>f(n);//最大数
	vector<double>g(n);//最小数
	int mx = nums[0];
	f[0] = g[0] = nums[0];
	for (int i = 1; i < n; i++)
	{
		if (nums[i] > 0)
		{
			f[i] =(double) max(f[i - 1] * nums[i],(double)nums[i]);
			g[i] = (double)min(g[i - 1] * nums[i], (double)nums[i]);
		}
		if (nums[i] < 0)
		{
			f[i] = (double)max(g[i - 1] * nums[i], (double)nums[i]);
			g[i] = (double)min(f[i-1] * nums[i], (double)nums[i]);
		}
		mx = (double)max((double)mx,f[i]);
	}
	return mx;
    }
};
