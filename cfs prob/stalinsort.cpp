#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        int cntr = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                cntr++;
            }
        }
        ans = min(ans, cntr);
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}