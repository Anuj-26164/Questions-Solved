#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        long long h;
        cin >> n >> m >> h;

        vector<long long> orig(n), value(n);
        for (int i = 0; i < n; i++)
        {
            cin >> orig[i];
            value[i] = orig[i];
        }

        vector<int> lastUpdate(n, 0);
        int lastResetTime = 0;
        int curTime = 0;

        while (m--)
        {
            int b;
            long long c;
            cin >> b >> c;
            --b;
            ++curTime;

            if (lastUpdate[b] <= lastResetTime)
                value[b] = orig[b];

            value[b] += c;
            lastUpdate[b] = curTime;

            if (value[b] > h)
            {
                lastResetTime = curTime;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (lastUpdate[i] > lastResetTime)
                cout << value[i] << " ";
            else
                cout << orig[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
