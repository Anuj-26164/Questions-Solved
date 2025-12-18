#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long int
#define forl for (int i = 0; i < n; i++)
#define nl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        if (x == 0 && y == 0)
        {
            cout << 0 << nl;
            continue;
        }
        if (x <= k && y == 0)
        {
            cout << 1 << nl;
            continue;
        }
        if (x <= k && y > 0 && y <= k)
        {
            cout << 2 << nl;
            continue;
        }
        else
        {
            ll a = (x + k - 1) / k;
            ll b = (y + k - 1) / k;
            if (a <= b)
                cout << 2 * b << nl;
            else
                cout << 2 * a - 1 << nl;
        }
    }
    return 0;
}