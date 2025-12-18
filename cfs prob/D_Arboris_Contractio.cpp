#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;
ll mod2 = 998244353;

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n);
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> isLeaf(n);
    ll totalLeaf = 0;
    for (ll i = 0; i < n; i++)
        totalLeaf += adj[i].size() == 1;

    ll ans = INT_MAX;
    for (ll i = 0; i < n; i++)
    {
        ll ct = totalLeaf - (adj[i].size() == 1);
        for (ll j : adj[i])
            ct -= adj[j].size() == 1;
        ans = min(ans, ct);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}