#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> cnt(m, 0);    // how many sets contain element i
    int t = 0;                // how many elements currently covered
    vector<vector<int>> v(n); // store all sets

    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        v[i].resize(l);
        for (int j = 0; j < l; j++)
        {
            cin >> v[i][j];
            v[i][j]--;             // make it 0-indexed
            if (cnt[v[i][j]] == 0) // if not covered before
                t++;               // increase total covered
            cnt[v[i][j]]++;        // increment coverage
        }
    }

    int ans = (t == m); // check if all m are covered at least once

    for (int i = 0; i < n; i++)
    {
        // remove set i temporarily
        for (int x : v[i])
        {
            cnt[x]--;
            if (cnt[x] == 0)
                t--; // this element is no longer covered
        }

        if (t == m)
            ans++; // even without this set, everything is still covered

        // restore set i
        for (int x : v[i])
        {
            if (cnt[x] == 0)
                t++; // becomes covered again
            cnt[x]++;
        }
    }

    cout << (ans >= 3 ? "YES\n" : "NO\n");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
