#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

long long calc(char ch, const string &s)
{
    vector<long long> pos;
    for (int i = 0; i < (int)s.size(); i++)
        if (s[i] == ch)
            pos.push_back(i);

    if (pos.empty())
        return LLONG_MAX;

    int k = pos.size();
    vector<long long> adj(k);
    for (int i = 0; i < k; i++)
        adj[i] = pos[i] - i;

    long long med = adj[k / 2];

    long long cost = 0;
    for (int i = 0; i < k; i++)
        cost += llabs(adj[i] - med);

    return cost;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long ans = min(calc('a', s), calc('b', s));
    cout << ans << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    solve();
}
