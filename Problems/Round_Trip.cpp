// Qs: Round_Trip
// Time: 14:09:41

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define int long long
#define ll long long
#define f(i, k, n) for (int i = k; i < n; i++)
#define nl '\n'
#define vin(v, n)               \
    vl v(n);                    \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> v[i];            \
    }
#define vout(v, n)                  \
    do                              \
    {                               \
        for (int i = 0; i < n; i++) \
            cout << v[i] << " ";    \
        cout << "\n";               \
    } while (0)
#define ff first
#define ss second
#define DP1(v, n) vector<long long> v((n) + 1, -1)
#define DP2(v, n, m) vector<vector<long long>> v((n) + 1, vector<long long>((m) + 1, -1))
#define pll pair<long long, long long>
#define debug(x) cerr << #x << " = " << x << nl;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (size_t i = 0; i < v.size(); i++)
        os << (i ? ", " : "") << v[i];
    return os << "]";
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &s)
{
    os << "{";
    bool f = true;
    for (auto &x : s)
        os << (f ? "" : ", ") << x, f = false;
    return os << "}";
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &m)
{
    os << "{";
    bool f = true;
    for (auto &x : m)
        os << (f ? "" : ", ") << x, f = false;
    return os << "}";
}

void yes()
{
    cout << "YES" << endl;
}

void no()
{
    cout << "NO" << endl;
}

int msb(int mask)
{
    if (mask == 0)
        return -1;
    return 63 - __builtin_clzll(mask);
}
#define lsb(mask) __builtin_ctzll(mask) /// 0 -> 64
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))

// const int N = 1001, M = 11, MOD = 1e9 + 7;
// ll n, m, dp[M][N][N];
vector<int> ans;
void dfs(int p, int c, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &pvis)
{
    if(!ans.empty())
        return;
    vis[c] = true;
    pvis.push_back(c);
    for (auto neigh : adj[c])
    {
        if (!vis[neigh])
        {
            dfs(c, neigh, vis, adj, pvis);
        }
        else
        {
            if (neigh != p && pvis.size() >= 3 && ans.size() == 0) // cycle found
            {
                for (int i = 0; i < pvis.size(); i++)
                {
                    if (pvis[i] == neigh)
                        while (i < pvis.size())
                        {
                            ans.push_back(pvis[i]);
                            i++;
                        }
                }
                ans.push_back(neigh);
                return;
            }
        }
    }
    pvis.pop_back();
    return;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }
    vector<bool> vis(n + 1, false);
    vector<int> pvis;
    f(i,1,n+1)
    if(!vis[i])
    dfs(-1, i, vis, adj, pvis);
    if (ans.size() == 0)
        cout << "IMPOSSIBLE";
    else
    {
        cout << ans.size() << nl;
        for (auto x : ans)
            cout << x << " ";
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    {
        solve();
    }
    return 0;
}