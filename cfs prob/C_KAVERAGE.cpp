#include <bits/stdc++.h>
using namespace std;




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        ll total_sum = 0;

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                ll val;
                cin >> val;
                total_sum += val;
            }
        }
        bool avg = false;
        while (n > 0)
        {
            if (total_sum == (ll)k * n * n)
            {
                avg = true;
                break;
            }
            else
                n--;
        }
        cout << (avg ? "YES" : "NO") << endl;
    }
    return 0;
}