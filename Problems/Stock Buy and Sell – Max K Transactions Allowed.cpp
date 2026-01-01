#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// const int MOD = 1e9 + 7;

class Solution
{
public:
    int n;
    int dp[1001][2][201];
    int maxp(int idx, int buy, int k, vector<int> &prices)
    {
        if (idx == n || k == 0)
            return 0;
        if (dp[idx][buy][k] != -1)
            return dp[idx][buy][k];
        if (buy)
            return dp[idx][buy][k] = max(-prices[idx] + maxp(idx + 1, 0, k, prices), maxp(idx + 1, 1, k, prices));
        else
            return dp[idx][buy][k] = max(prices[idx] + maxp(idx + 1, 1, k - 1, prices), maxp(idx + 1, 0, k, prices));
    }
    int maxProfit(vector<int> &prices, int k)
    {
        // code here
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return maxp(0, 1, k, prices);
    }
};
