#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<pair<pair<int, int>, int>> v(n);
        for (auto &[x, y] : v)
        {
            cin >> x.first >> x.second;
            x.second = -x.second;
        }
        for (int i = 0; i < n; i++)
            v[i].second = i;

        sort(v.begin(), v.end());
        int mn = -1e9;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (v[i].first.first > mn)
            {
                mn = v[i].first.first;
                ans.push_back(v[i].second + 1);
            }
        }
        cout << ans.size() << "\n";
        for (auto &x : ans)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}