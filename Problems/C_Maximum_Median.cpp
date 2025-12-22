// Qs: C_Maximum_Median
// Time: 21:07:55

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

bool pred(vl &arr, ll k, ll num)
{
    ll sum = 0;
    for (int i = (arr.size() - 1) / 2; i < arr.size(); i++)
    {
        sum += max(0LL,(num - arr[i]));
    }
    if (sum <= k)
        return 1;
    if (sum > k)
        return 0;
}

int main()
{
    ll n, k;
    read2(n, k);
    vin(arr, n);
    sort(arr.begin(), arr.end());
    ll lo = 0, hi = 1e10, mid;
    while (hi - lo > 1)
    {
        mid=(hi+lo)/2;
        if(pred(arr,k,mid))
        {
            lo=mid;
        }
        else
        {
            hi=mid-1;
        }
    }
    if(pred(arr,k,hi)) print(hi);
    else print(lo);
    return 0;
}