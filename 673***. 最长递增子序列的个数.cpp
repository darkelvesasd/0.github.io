class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int>f(n,1);//以i结尾序列最大长度
	vector<int>g(n,1);//以i结尾序列最大长度数
	int retc = 1;
	int len = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
			{
				if (f[j] + 1 == f[i])
				{
					g[i] += g[j] ;
				}
				else
					if (f[j] + 1 > f[i])
					{
						g[i] = g[j];
						f[i] = f[j] + 1;
					}
			}
		}
		if (len == f[i])
		{
			retc += g[i];
		}
		if (len < f[i])
		{
			len = f[i];
			retc = g[i];
		}
	}
	return retc;
    }
};
