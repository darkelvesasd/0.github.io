class Solution {
public:
    int getMaxLen(vector<int>& nums) {
	int n = nums.size();
	vector<int> f(n+1);//n结尾最大正数
	vector<int> g(n+1);//n结尾最大负数
	int mx = 0;
	for (int i = 1; i <= n; i++)
	{
		if (nums[i - 1] > 0)
		{
			f[i] = f[i - 1] + 1;
			g[i] = g[i - 1] ==0?0:g[i-1]+1;
		}
		else 
			if (nums[i - 1] < 0)
			{
				f[i] = g[i - 1] == 0 ?0: g[i - 1] + 1;
				g[i] = f[i - 1] + 1;
			}
		mx = max(mx, f[i]);
	}
	return  mx;
    }
};
