// Qs: B_Large_Array_and_Segments
// Time: 18:58:09

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

bool pred(ll x, ll n, ll idx, vl &a, ll z, ll k)
{
    ll sum = 0;
    sum += (z) * (n * k - idx + 1) / n;
    idx--;
    for(int i=n-1;i>=(idx%n);i--) sum+=a[i];
    return sum >= x;
}
ll n;
void solve()
{
    ll k, x;
    read3(n, k, x);
    vin(a, n);
    ll lo = 1, hi = n * k, mid;
    ll z = accumulate(a.begin(), a.end(), 0LL);
    if(x>z*k) print(0);
    else
    {
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (pred(x, n, mid, a, z, k))
                lo = mid;
            else
                hi = mid - 1;
        }
        if (pred(x, n, hi, a, z, k))
            print(hi);
        else
            print(lo);
    }
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