#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    vector<long long> a(n), b(n);
    for (int i = 1; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        cin >> b[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(2, 1e18));

    // base case
    dp[1][0] = 0;
    dp[1][1] = c;

    for (int i = 1; i < n; i++)
    {
        // stairs
        dp[i + 1][0] = min(
            dp[i][0] + a[i],
            dp[i][1] + a[i]);

        // elevator
        dp[i + 1][1] = min(
            dp[i][0] + c + b[i],
            dp[i][1] + b[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
    cout << "\n";

    return 0;
}
