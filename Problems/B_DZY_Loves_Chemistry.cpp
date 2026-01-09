#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> fa;

int find_set(int x)
{
    if (fa[x] != x)
        fa[x] = find_set(fa[x]);
    return fa[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    fa.resize(n + 1);

    for (int i = 1; i <= n; i++)
        fa[i] = i;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        fa[find_set(x)] = find_set(y);
    }

    long long ans = 1LL << n;
    for (int i = 1; i <= n; i++)
        if (find_set(i) == i)
            ans >>= 1;

    cout << ans << '\n';
    return 0;
}
