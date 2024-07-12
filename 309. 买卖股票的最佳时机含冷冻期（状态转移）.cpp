#include<vector>
#include<iostream>
using namespace std;
int main()
{
	vector<int> prices = { 1};
	int n = prices.size();
	vector<int> dp1(n);//ÂòÈë
	vector<int> dp2(n);//¿É
	vector<int> dp3(n);//Àä
	if (n == 1)
	{
		return 0;
	}
	dp1[0] = -prices[0];
	dp2[0] = 0;
	dp3[0] = 0;
	for (int i = 1; i < n; i++)
	{
		dp1[i] = max(dp2[i-1]-prices[i],dp1[i-1]);
		dp2[i] = max(dp2[i - 1], dp3[i - 1]);
		dp3[i] = dp1[i - 1] + prices[i];
	}
	cout << max(dp2[n - 1], dp3[n - 1]);
	return 0;
}
