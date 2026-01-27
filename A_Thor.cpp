#include <bits/stdc++.h>
using namespace std;

struct Fenwick
{
    int n;
    vector<int> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int i, int v)
    {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }

    int sum(int i)
    {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Fenwick fw(q);
    vector<vector<int>> app(n + 1);
    vector<int> ptr(n + 1, 0);
    vector<char> read(q + 1, 0);

    int curId = 0;
    int lastCleared = 0;

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            curId++;
            app[x].push_back(curId);
            fw.add(curId, 1);
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            while (ptr[x] < (int)app[x].size())
            {
                int id = app[x][ptr[x]];
                ptr[x]++;
                if (!read[id])
                {
                    read[id] = 1;
                    fw.add(id, -1);
                }
            }
        }
        else
        {
            int t;
            cin >> t;
            t = min(t, curId);
            for (int i = lastCleared + 1; i <= t; i++)
            {
                if (!read[i])
                {
                    read[i] = 1;
                    fw.add(i, -1);
                }
            }
            lastCleared = max(lastCleared, t);
        }

        cout << fw.sum(curId) << "\n";
    }
    return 0;
}
