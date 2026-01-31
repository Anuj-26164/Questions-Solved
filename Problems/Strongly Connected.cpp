#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define int long long
#define ll long long
#define f(i, k, n) for (int i = k; i < n; i++)
#define nl endl
#define vin(v, n)               \
    vl v(n);                    \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> v[i];            \
    }
#define vout(v, i, k, n)            \
    do                              \
    {                               \
        for (int i = k; i < n; i++) \
            cout << v[i] << " ";    \
        cout << "\n";               \
    } while (0)
#define ff first
#define ss second
#define MOD 1000000007LL
const ll INF = 4e18;
template <class T, class Container = vector<T>>
using maxheap = priority_queue<T, Container, less<T>>;
template <class T, class Container = vector<T>>
using minheap = priority_queue<T, Container, greater<T>>;
#define DP1(v, n) vector<long long> v((n) + 1, -1)
#define DP2(v, n, m) vector<vector<long long>> v((n) + 1, vector<long long>((m) + 1, -1))
#define pll pair<long long, long long>

class Solution
{
public:
    void dfs(bool x,int node, vector<bool> &vis, vector<vector<int>> &adj, stack<int> &s)
    {
        // action on vertex when entering
        vis[node] = true; // example initialization (change as needed)

        for (int child : adj[node])
        {
            if (vis[node])
                continue;

            // action before going to child
            dfs(true,child, vis, adj, s);

            // action after returning from child
            // dp[node] += dp[child]; // example: subtree sum / size
        }
        // action on vertex before exiting
        if(x)
        s.push(node);
    }
    int kosaraju(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> finish(n, -1);
        vector<bool> vis(n, false);
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs(true,i, vis, adj, s);
        vis.assign(n,false);
        vector<vector<int>> adj1(n);
        f(i,0,n)
        {
            for(auto y:adj[i])
            {
                adj1[y].push_back(i);
            }
        }
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if(!vis[node])
            {
                dfs(false,node, vis, adj1, s);
                ans++;
            }
        }
        return ans;
    }
};
