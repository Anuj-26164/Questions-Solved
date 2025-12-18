// Qs: C_Very_Easy_Task
// mid: 21:31:45

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
bool pred(ll mid, ll n, ll x, ll y)
{
    ll cnt = (mid) / x + (mid) / y;
    if (cnt >= n)
        return 1;
    else
        return 0;
}

int main()
{
    ll n, x, y;
    read3(n, x, y);
    if (n == 1)
    {
        print(min(x, y));
    }
    else
    {
        ll lo = 0, hi = (n - 1) * max(x, y), mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (pred(mid, n - 1, x, y)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
    
        print(lo + min(x, y));
    }
    return 0;
}