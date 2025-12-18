#include <bits/stdc++.h>
using namespace std;

string s;
long long dp[20][200][2]; // pos, sum, tight

long long solve(int pos, int sum, int tight)
{
    if (sum > 50)
        return 0;
    if (pos == s.size())
        return (sum == 50);
    if (dp[pos][sum][tight] != -1)
        return dp[pos][sum][tight];

    int limit = tight ? (s[pos] - '0') : 9;
    long long res = 0;

    for (int d = 0; d <= limit; d++)
    {
        res += solve(pos + 1, sum + d, tight && (d == limit));
    }

    return dp[pos][sum][tight] = res;
}

int main()
{
    long long n = 1e18;
    s = to_string(n);
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 1) << "\n";
}
 