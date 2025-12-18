#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
const ll INF = (ll)9e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll W;
    if (!(cin >> n >> W))
        return 0;
    vl w(n), v(n);
    ll Vsum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i] >> v[i];
        Vsum += v[i];
    }

    vector<ll> dp(Vsum + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        ll wi = w[i], vi = v[i];
        for (ll val = Vsum; val >= vi; --val)
        {
            if (dp[val - vi] != INF)
                dp[val] = min(dp[val], dp[val - vi] + wi);
        }
    }

    ll ans = 0;
    for (ll val = 0; val <= Vsum; ++val)
        if (dp[val] <= W)
            ans = max(ans, val);

    cout << ans << "\n";
    return 0;
}
