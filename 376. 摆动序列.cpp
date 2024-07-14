	int n = nums.size();
	vector<int>f(n,1);//以上升状态结束的最长序列
	vector<int>g(n, 1);//以下降状态结束的最长序列
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
			{
				f[i] = max(f[i],g[j] + 1);
				g[i] = 1;
			}
			if (nums[i] < nums[j])
			{
				f[i] = 1;
				g[i] = max(g[i],f[j] + 1);
			}
			/*if (nums[i] == nums[j])
			{
				f[i] = max(f[j], f[i]);
				g[i] = max(g[j], g[j]);
			}*/
		}
	}
//	cout << n << endl;
	return max(f[n-1],g[n-1]);
