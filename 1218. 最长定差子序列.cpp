class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
	int mx = 1;
	unordered_map<int,int>hash;
	int n = arr.size();
	 hash[arr[0]] = 1;
	for (int i = 1; i < n; i++)
	{
		hash[arr[i]] = hash[arr[i] - difference] + 1;
		mx = max(hash[arr[i]], mx);
	}
	//cout << sizeof(hash);
	return mx;
    }
};
