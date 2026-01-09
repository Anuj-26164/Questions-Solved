#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t;i++)
    {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> depth(n + 1, -1);
        queue<int> q;
        q.push(1);
        depth[1] = 0;
        int ans = 1;
        while (!q.empty())
        {
            int sz = q.size();
            ans = max(ans, sz);

            for (int i = 0; i < sz; i++)
            {
                int u = q.front();
                q.pop();

                for (int v : adj[u])
                {
                    if (depth[v] == -1)
                    {
                        depth[v] = depth[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            int cnt = 1;
            for(auto x:adj[i]) if(depth[x]==depth[i]+1)
                    cnt++;
            ans = max(ans, cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}
