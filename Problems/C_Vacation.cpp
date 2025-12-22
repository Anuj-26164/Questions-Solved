#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> vac(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> vac[i][0] >> vac[i][1] >> vac[i][2];

    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = vac[0][0];
    dp[0][1] = vac[0][1];
    dp[0][2] = vac[0][2];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = vac[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = vac[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = vac[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
}
