#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vin(v, n)               \
    vector<ll> v(n);            \
    for (int i = 0; i < n; i++) \
        cin >> v[i];

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

map<ll, int> factorize(ll x)
{
    map<ll, int> factors;
    for (ll i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            factors[i]++;
            x /= i;
        }
    }
    if (x > 1)
        factors[x]++;
    return factors;
}

void solve()
{
    int n;
    cin >> n;
    vin(a, n);

    map<ll, ll> total_factors;

    for (auto x : a)
    {
        map<ll, int> f = factorize(x);
        for (auto &[prime, cnt] : f)
        {
            total_factors[prime] += cnt;
        }
    }

    for (auto &[prime, cnt] : total_factors)
    {
        if (cnt % n != 0)
        {
            no();
            return;
        }
    }

    yes();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
