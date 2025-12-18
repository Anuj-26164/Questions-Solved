#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int diameter = 0;

int dfs(int u, int parent)
{
    int max1 = 0, max2 = 0; // tallest and second tallest child heights

    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        int h = dfs(v, u);
        if (h > max1)
        {
            max2 = max1;
            max1 = h;
        }
        else if (h > max2)
        {
            max2 = h;
        }
    }

    diameter = max(diameter, max1 + max2); // sum of two tallest
    return max1 + 1;                       // height of current node
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    cout << diameter << "\n"; // diameter in edges
}
