#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    ll x = 0, y = 0, ma = 0, m = 0;
    for (ll i = 0; i < n; i += 2)
    {
        ma = max(ma, a[i]);
        x++;
    }
    x += ma;
    for (ll i = 1; i < n; i += 2)
    {
        m = max(m, a[i]);
        y++;
    }
    y += m;
    cout << max(x, y) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
