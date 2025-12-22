// Qs: A_Milya_and_Two_Arrays
// Time: 10:34:04

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
        ll n;
        cin >> n;
        set<ll> a, b;
        f(0, n)
        {
            ll x;
            cin >> x;
            a.insert(x);
        }
        f(0, n)
        {
            ll x;
            cin >> x;
            b.insert(x);
        }
        ll bsize = b.size();
        ll asize = a.size();
        if ((bsize == 1 && asize >= 3) || (bsize == 2 && asize >= 2) || (bsize >= 3))
        {
            yes();
        }
        else
        {
            no();
        }
    }
    return 0;
}