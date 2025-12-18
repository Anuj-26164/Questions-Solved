
// Qs: B_Parity_and_Sum
// Time: 03:07:44

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'

void yes()
{
    cout << "YES" << endl;
}

void no()
{
    cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, cnt = 0;
        cin >> n;
        vl arreven, arrodd;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (x & 1)
                arrodd.pb(x);
            else
                arreven.pb(x);
        }
        if (arreven.size() == n || arrodd.size() == n)
            cout << 0 << nl;
        else
        {
            cnt = arreven.size();
            sort(arrodd.begin(), arrodd.end());
            sort(arreven.begin(), arreven.end());
            for (int i = 0; i < arreven.size(); i++)
            {
                if (arreven[i] >= arrodd[arrodd.size() - 1])
                {
                    cnt = arreven.size() + 1;
                }
                else
                {
                    arrodd[arrodd.size() - 1] += arreven[i];
                }
            }
            cout << cnt << nl;
        }
    }
    return 0;
}