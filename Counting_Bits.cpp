#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;

    for (ll k = 0; (1LL << k) <= n; k++)
    {
        ll cycle = 1LL << (k + 1);
        ll full = (n + 1) / cycle;
        ll rem = (n + 1) % cycle;

        ans += full * (1LL << k);
        ans += max(0LL, rem - (1LL << k));
    }

    cout << ans << "\n";
}
