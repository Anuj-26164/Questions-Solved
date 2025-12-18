#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        if (!(cin >> n))
            return 0;
        vl v(n + 1);
        for (ll i = 1; i <= n; ++i)
            cin >> v[i];

        vl dp(n + 1, 1);

        for (ll i = n; i >= 1; --i)
        {
            for (ll j = 2 * i; j <= n; j += i)
            {
                if (v[j] > v[i])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        ll ans = 0;
        for (ll i = 1; i <= n; ++i)
            ans = max(ans, dp[i]);
        cout << ans << '\n';
    }
    return 0;
}
