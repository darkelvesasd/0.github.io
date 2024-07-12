class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
	if (n == 0)
	{
		return 0;
	}
	int mi =prices[0];
	int ma = -0x3f3f3f3f;
	for (int i = 1; i < n; i++)
	{
        mi = min(mi, prices[i]);
		ma = max(ma, prices[i] - mi);
	}
	return max(0,ma);
    }
};
