// TL: 1s
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lcm(a, b) a *(b / __gcd(a, b))
#define gcd(a, b) __gcd(a, b)
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define PI 3.1415926535897932384626
#define vi vector<int>
#define vll vector<ll>
#define VI(x, n)                \
    vector<int> x(n);           \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> x[i];            \
    };
#define VLL(x, n)               \
    vector<ll> x(n);            \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> x[i];            \
    };

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<bool>> dp(n, vector<bool>(2, false));
    dp[0][1] = true;
    dp[0][0] = true;

    for (int i = 1; i < n; i++)
    {
        for (int left = 0; left <= 1; left++)
        {
            if (s[i] == '1')
            {
                dp[i][left] = dp[i - 1][1];
                continue;
            }

            if (!left || s[i - 1] == '0')
            {
                dp[i][left] = dp[i - 1][1] || dp[i - 1][0];
            }
            else if (i >= 2 && s[i - 2] == '0')
            {
                dp[i][left] = dp[i - 2][0];
            }
            else
            {
                dp[i][left] = false;
            }
        }
    }

    cout << ((dp[n - 1][0] || dp[n - 1][1]) ? "YES" : "NO") << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t{};
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}