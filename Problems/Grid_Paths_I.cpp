#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'

ll gridPathobs(int k, int m, vector<string> &v, vector<vector<ll>> &dp, int n)
{
    if (k == 0 && m == 0)
        return (v[0][0] == '*') ? 0 : 1;
    if (k < 0 || m < 0 || v[k][m] == '*')
        return 0;
    if (dp[k][m] != -1)
        return dp[k][m];
    return dp[k][m] = (gridPathobs(k - 1, m, v, dp, n) + gridPathobs(k, m - 1, v, dp, n)) % 1000000007;
}

void solve()
{
    ll n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    cout << gridPathobs(n - 1, n - 1, v, dp, n) << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
