#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> adj[N];
int color[N];
int tin[N], tout[N], flat[N];
int timer = 0;

struct Query
{
    int l, r, id;
    bool operator<(const Query &other) const
    {
        return r < other.r;
    }
};

struct BIT
{
    int n;
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1, 0) {}

    void update(int i, int v)
    {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }

    int query(int i)
    {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    int range(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

void dfs(int v, int p)
{
    tin[v] = ++timer;
    flat[timer] = color[v];
    for (int u : adj[v])
    {
        if (u == p)
            continue;
        dfs(u, v);
    }
    tout[v] = timer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> color[i];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    vector<Query> queries;
    for (int v = 1; v <= n; v++)
    {
        queries.push_back({tin[v], tout[v], v});
    }

    sort(queries.begin(), queries.end());

    BIT bit(n);
    unordered_map<int, int> last;
    vector<int> ans(n + 1);

    int qptr = 0;
    for (int i = 1; i <= n; i++)
    {
        int c = flat[i];
        if (last.count(c))
        {
            bit.update(last[c], -1);
        }
        bit.update(i, 1);
        last[c] = i;

        while (qptr < n && queries[qptr].r == i)
        {
            ans[queries[qptr].id] =
                bit.range(queries[qptr].l, queries[qptr].r);
            qptr++;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    cout << "\n";
    return 0;
}
