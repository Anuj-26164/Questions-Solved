#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1), pref(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] ^ a[i]; // prefix xor
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;                  // 1-based
        ll ans = pref[r] ^ pref[l - 1]; // xor on [l, r]
        cout << ans << '\n';
    }

    return 0;
}
