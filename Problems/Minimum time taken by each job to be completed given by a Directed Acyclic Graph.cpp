class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
    {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                ans[i] = 1;
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int nxt : adj[node])
            {
                ans[nxt] = max(ans[nxt], ans[node] + 1);
                indegree[nxt]--;

                if (indegree[nxt] == 0)
                    q.push(nxt);
            }
        }

        return ans;
    }
};
