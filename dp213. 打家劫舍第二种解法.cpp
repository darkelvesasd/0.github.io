#include<vector>
#include<iostream>
using namespace std;
int rob1(vector<int>& nums, int a, int b)
{
	int n = nums.size();
		vector<int>f(n);//
		vector<int>g(n);
		if (b < a)
		{
			return 0;
		}
		if (b == a)
		{
			return nums[a];
		}
		f[a] = nums[a];
		g[a] = 0;
		for (int i=a;i<=b;i++)
		{
			f[i] = g[i-1] + nums[i];
			g[i] = max(g[i-1],f[i-1]);
		}
		return max(g[b],f[b]);
}
int main()
{
	vector<int> nums = { 1,2,3 };
	int n = nums.size();
	int ma = max(rob1(nums,1,n-1),rob1(nums,2,n-2)+nums[0]);
	cout << ma;
	return 0;
}
