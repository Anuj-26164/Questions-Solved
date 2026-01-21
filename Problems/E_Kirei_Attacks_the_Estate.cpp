#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
const int MAXN = 200000;

vector<int> tree[MAXN + 1];
ll a[MAXN + 1];
ll ans[MAXN + 1];
int depth[MAXN + 1];

void dfs(int v, int p, int gp)
{
    if (p == -1 && gp == -1) // root
        ans[v] = a[v];
    else if (gp == -1) // just below root
        ans[v] = max(a[v], a[v] - a[1]);
    else //arbitrary node
        ans[v] = max(a[v], a[v] - a[p] + ans[gp]);
    for(auto child:tree[v])
    {
        if(child==p) continue;
        dfs(child, v, p);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            tree[i].clear();
            ans[i] = 0;
        }

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        ans[1] = a[1];
        dfs(1, -1, -1);
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
