class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        string s1 = " " + s;
	unordered_set<string> hash;
	for (auto s : wordDict)
	{
		hash.insert(s);
	}
	int n = s1.length();
	vector<bool>dp(n);//保证以n结尾的字符都可以被拼接
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (dp[j-1] && hash.count(s1.substr(j, i - j+1)))
			{
				dp[i] = 1;
				break;
			}
		}
	}
	return dp[n - 1];
    }
};
