#include <bits/stdc++.h>
using namespace std;
main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long a[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        long long b[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        long long ans[n + 1];
        for (int i = n; i >= 1; i--)
        {
            ans[i] = lcm(a[i], b[i]);
        }
        bool ch = 1;
        if (ans[1] != a[1])
            ch = 0;
        if (ans[n] != b[n])
            ch = 0;
        for (int i = 2; i <= n; i++)
        {
            if (__gcd(a[i - 1], ans[i]) != a[i])
            {
                ch = 0;
            }
        }
        for (int i = n - 1; i >= 1; i--)
        {
            if (__gcd(b[i + 1], ans[i]) != b[i])
            {
                ch = 0;
            }
        }
        if (ch)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
}