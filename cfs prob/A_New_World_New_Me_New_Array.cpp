// Qs: A_New_World_New_Me_New_Array
// Time: 20:09:23

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'
#define vin(v, n) \
    vl v(n);      \
    for (0, n)    \
        cin >> v[i];

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
        ll n, k, p;
        cin >> n >> k >> p;
        if (k >= (-n * p) && k <= (n * p))
        {
            if (k % p)
                cout << abs(k) / p + 1 << nl;
            else
                cout << abs(k) / p << nl;
        }
        else
        {
            cout << -1 << nl;
        }
    }
    return 0;
}