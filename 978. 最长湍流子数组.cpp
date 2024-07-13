class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
	int n = arr.size();
	vector<int> f(n,1);//最后上升的数组
	vector<int> g(n,1);//最后下降的数组
	int mx = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i - 1])
		{
			f[i] = g[i - 1] + 1;
			g[i] = 1;
		}
		else if(arr[i] < arr[i - 1])
		{
			g[i] = f[i - 1] + 1;
			f[i] = 1;
		}
		mx = max(mx, max(f[i], g[i]));
	}
//	cout << mx;
	return mx;
    }
};
