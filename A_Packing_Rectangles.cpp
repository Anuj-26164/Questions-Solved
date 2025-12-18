// Qs: A_Packing_Rectangles
// Time: 16:30:21

#include <bits/stdc++.h>
using namespace std;

#define read(x) scanf("%lld", &x)
#define read2(x, y) scanf("%lld %lld", &x, &y)
#define read3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define print(x) printf("%lld\n", x)
#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'
#define vin(v, n)               \
    vl v(n);                    \
    for (int i = 0; i < n; i++) \
        cin >> v[i];

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
ll w, h, n, lo, hi, mid;

bool good(ll x)
{
    return (x / h) * (x / w) >= n;
}
int main()
{
    read3(w, h, n);
    lo = 0;
    hi = 1;
    while (!good(hi))
    {
        hi *= 2;
    }
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (good(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    print(hi);
    return 0;
}