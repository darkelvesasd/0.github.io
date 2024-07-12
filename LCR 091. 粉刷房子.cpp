#include<vector>
#include<iostream>
using namespace std;
int main()
{
	vector<vector<int>> costs = { {17, 2, 17} };
	int n = costs.size();
	vector<int>f(n);
	vector<int>g(n);
	vector<int>h(n);
	f[0] = costs[0][0];
	g[0] = costs[0][1];
	h[0] = costs[0][2];
	if (n == 1)
	{
		return min(min(f[0], g[0]), h[0]);
	}
	for (int i = 1; i < n; i++)
	{
		f[i] = min(g[i-1], h[i-1])+costs[i][0];
		g[i] = min(f[i - 1], h[i - 1]) + costs[i][1];
		h[i] = min(f[i - 1], g[i - 1]) + costs[i][2];
	}
	cout << min(min(f[n - 1], g[n - 1]), h[n - 1]);
	return min(min(f[n-1], g[n-1]), h[n-1]);
}
