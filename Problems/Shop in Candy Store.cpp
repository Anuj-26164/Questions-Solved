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
    vector<int> minMaxCandy(vector<int> prices, int k)
    {
        sort(prices.begin(), prices.end());
        int n = prices.size();

        int minCost = 0, maxCost = 0;

        // 🔽 Minimum cost
        int i = 0, j = n - 1;
        while (i <= j)
        {
            minCost += prices[i];
            i++;
            j -= k;
        }

        // 🔼 Maximum cost
        i = 0;
        j = n - 1;
        while (i <= j)
        {
            maxCost += prices[j];
            j--;
            i += k;
        }

        return {minCost, maxCost};
    }
};
