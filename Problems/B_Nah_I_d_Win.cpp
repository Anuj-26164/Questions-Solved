#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define ll long long int
#define nl '\n'

ll numofdiv(ll c)
{
    ll count = 0;
    for (ll i = 1; i * i <= c; i++)
    {
        if (c % i == 0)
        {
            count++;
            if (i != c / i)
                count++;
        }
    }
    return count;
}
ll kthsmallestdivisor(ll c, ll k)
{
    vector<ll> divisors;
    for (ll i = 1; i * i <= c; i++)
    {
        if (c % i == 0)
        {
            divisors.push_back(i);
            if (i != c / i)
                divisors.push_back(c / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    if (k > divisors.size() || k <= 0)
        return -1;
    return divisors[k - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, l;
    cin >> n >> k >> l;
    if (n <= 0 || k <= 0)
    {
        cout << -1 << nl;
        return 0;
    }
    if (k > numofdiv(n))
    {
        cout << -1 << nl;
        return 0;
    }
    ll z = n, x = -1;
    for (int i = 0; i < l; i++)
    {
        x = kthsmallestdivisor(z, k);
        if (x == -1)
        {
            cout << -1 << nl;
            return 0;
        }
        z = x;
    }

    cout << x << nl;
    return 0;
}