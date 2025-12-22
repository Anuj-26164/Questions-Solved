#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;

ll mod_exp(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    ll m = 63 - __builtin_clzll(k); 

    if ((1LL << m) == k)
    {
        cout << mod_exp(n, m) << "\n";
        return;
    }

    ll z = k - (1LL << m);
    ll ans = mod_exp(n, m);

    ll p = 1;
    for (int i = 0; i < 63; i++)
    {
        if (z & (1LL << i))
        {
            ans = (ans + p) % MOD;
        }
        p = (p * n) % MOD;
    }

    cout << ans % MOD << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
