class Solution {
public:
    int findSubstringInWraproundString(string s) {
	int n = s.length();
	vector<int> a(n,1);//储存以当前字母结尾的最大值
	vector<int>b(26);//储存26个字母的最大值
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (s[i - 1] + 1 == s[i] || s[i - 1] == 'z' && s[i] == 'a')
		{
			a[i] =1+ a[i - 1];
		}
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[j] == 97 + i)
			{
				b[i] = max(b[i], a[j]);
			}
		}
		sum += b[i];
	}
	return sum;
    }
};
