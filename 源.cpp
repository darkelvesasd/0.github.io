#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>cost = { 1,100,1,1,1,100,1,1,100,1 };
    int len = cost.size();
    vector<int>dp(len);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < len; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
    }
    cout << min(dp[len-1], dp[len - 2]);
}