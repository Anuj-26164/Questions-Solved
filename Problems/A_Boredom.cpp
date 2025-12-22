#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<int> a(n);
    int maxv = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        maxv = max(maxv, a[i]);
    }

    vector<ll> cnt(maxv + 1, 0);
    for (int x : a)
        cnt[x]++;

    vector<ll> points(maxv + 1, 0);
    for (int v = 0; v <= maxv; ++v)
        points[v] = cnt[v] * 1LL * v;

    if (maxv == 0)
    {
        cout << points[0] << '\n';
        return 0;
    }

    vector<ll> dp(maxv + 1, 0);
    dp[0] = points[0];
    dp[1] = max(points[0], points[1]);
    for (int v = 2; v <= maxv; ++v)
    {
        dp[v] = max(dp[v - 1], dp[v - 2] + points[v]);
    }
    cout << dp[maxv] << '\n';
    return 0;
}
