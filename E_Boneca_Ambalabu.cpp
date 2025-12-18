#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define checkbit(mask, bit) (((mask) >> (bit)) & 1LL)

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];

    const int B = 31;
    long long setb[B] = {0};
    for (ll x : a)
    {
        for (int j = 0; j < B; ++j)
        {
            if (checkbit(x, j))
                ++setb[j];
        }
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i)
    {
        ll cur = 0;
        for (int j = 0; j < B; ++j)
        {
            if (checkbit(a[i], j))
                cur += (n - setb[j]) * (1LL << j);
            else
                cur += setb[j] * (1LL << j);
        }
        if (cur > ans)
            ans = cur;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
