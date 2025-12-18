// Qs: C_Equal_Values
// Time: 21:55:49

#include <bits/stdc++.h>
using namespace std;

#define read(x) scanf("%lld", &x)
#define read2(x, y) scanf("%lld %lld", &x, &y)
#define read3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define print(x) printf("%lld\n", x)
#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'
#define vin(v, n)               \
    vl v(n);                    \
    for (int i = 0; i < n; i++) \
        read(v[i]);

// bool isprime(int n) {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (int i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }
//     return true;

void yes()
{
    cout << "YES" << endl;
}

void no()
{
    cout << "NO" << endl;
}

#define msb(mask) (63 - __builtin_clzll(mask)) /// 0 -> -1
#define lsb(mask) __builtin_ctzll(mask)        /// 0 -> 64
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))

void solve()
{
    ll n;
    cin >> n;
    vin(arr, n);
    vl mincost;
    for (auto c : arr)
    {
        mincost.push_back(c * (n - 1));
    }
    vector<pair<int, int>> vp;
    ll first = 0, second = 1;
    while (second <= n) 
    {
        if (second == n || arr[second] != arr[first])
        {
            if(first!=second-1)
            {vp.push_back({first, second - 1});}
            first = second;
        }
        second++;
    }

    for (auto c : vp)
    {
         mincost.push_back(c.first * arr[c.first] + (n - c.second-1) * arr[c.first]);
        // cout << c.first << " " << c.second << nl;
    }
    sort(all(mincost));
    cout << mincost[0] << nl;
}
int main()
{
    ll t;
    read(t);
    while (t--)
    {
        solve();
    }
    return 0;
}