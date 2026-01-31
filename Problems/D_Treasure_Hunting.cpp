#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 4e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<ll> L(n + 1, INF), R(n + 1, -INF);
    for (ll i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        L[x] = min(L[x], y);
        R[x] = max(R[x], y);
    }

    vector<ll> safe(q);
    for (ll i = 0; i < q; i++)
        cin >> safe[i];
    sort(safe.begin(), safe.end());

    // nearest safe column
    auto leftSafe = [&](ll x)
    {
        auto it = upper_bound(safe.begin(), safe.end(), x);
        if (it == safe.begin())
            return -1LL;
        return *prev(it);
    };
    auto rightSafe = [&](ll x)
    {
        auto it = lower_bound(safe.begin(), safe.end(), x);
        if (it == safe.end())
            return -1LL;
        return *it;
    };

    // find last row with treasure
    while (n > 0 && L[n] == INF)
        n--;

    vector<array<ll, 2>> dp(n + 1, {INF, INF});

    // starting at (1,1)
    ll sL = rightSafe(1);
    dp[0][0] = dp[0][1] = abs(sL - 1);

    ll curL = sL, curR = sL;

    for (ll i = 1; i <= n; i++)
    {
        if (L[i] == INF)
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
            continue;
        }

        ll ls = leftSafe(L[i]);
        ll rs = rightSafe(R[i]);

        ll width = R[i] - L[i];

        // end at ls
        if (ls != -1)
        {
            dp[i][0] = min({dp[i - 1][0] + abs(curL - R[i]) + width + abs(L[i] - ls),
                            dp[i - 1][1] + abs(curR - R[i]) + width + abs(L[i] - ls)}) +
                       1;
        }

        // end at rs
        if (rs != -1)
        {
            dp[i][1] = min({dp[i - 1][0] + abs(curL - L[i]) + width + abs(R[i] - rs),
                            dp[i - 1][1] + abs(curR - L[i]) + width + abs(R[i] - rs)}) +
                       1;
        }

        curL = ls;
        curR = rs;
    }

    ll ans = min(dp[n][0], dp[n][1]);
    cout << ans << "\n";
}
