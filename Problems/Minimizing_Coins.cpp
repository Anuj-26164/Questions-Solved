#include <bits/stdc++.h>
using namespace std;

#define read(x) scanf("%lld", &x)
#define read2(x, y) scanf("%lld %lld", &x, &y)
#define print(x) printf("%lld\n", x)
#define vl vector<long long>
#define ll long long

const ll INF = 1e18;

void solve()
{
    ll n, sum;
    read2(n, sum);
    vl v(n);
    for (ll &x : v)
        read(x);

    vl dp(sum + 1, INF);
    dp[0] = 0;

    for (ll i = 1; i <= sum; ++i)
    {
        for (ll coin : v)
        {
            if (coin <= i)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    print(dp[sum] == INF ? -1 : dp[sum]);
}

int main()
{
    solve();
    return 0;
}
