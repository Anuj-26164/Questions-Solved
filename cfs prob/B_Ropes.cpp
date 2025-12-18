// Qs: B_Ropes
// Time: 21:16:05

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

bool pieces(vl &arr, double x, double k)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        ll cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            cnt += arr[i] / x;
        }
        if (cnt >= k)
            return 1;
        else
            return 0;
    }
}

int main()
{
    ll n, k;
    read2(n, k);
    vl arr(n);
    for (auto &c : arr)
        cin >> c;
    ll t = 100;
    double lo = 0, hi = 1e8, mid;
    while (t--)
    {
        mid = (hi + lo) / 2;
        if(pieces(arr,mid,k))
        {
            lo=mid;
        }
        else 
        {
            hi=mid;
        }
    }
    cout<<setprecision(7)<<hi;
    return 0;
}