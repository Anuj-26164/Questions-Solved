
#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'
#define vin(v, n)               \
    vl v(n);                    \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> v[i];            \
    }

long long bin_exp(long long base, long long exp)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base);
        base = (base * base);
        exp >>= 1;
    }
    return result;
}

// bool isprime(int n) {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (int i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }
//     return true;

long long nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r > n - r)
        r = n - r;
    long long res = 1;
    for (int i = 1; i <= r; i++)
    {
        res *= (n - r + i);
        res /= i;
    }
    return res;
}

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

ll sumOfdigits(ll num)
{
    if (num == 0)
        return 0;
    return (num % 10) + sumOfdigits(num / 10);
}

void solve()
{
    ll n;
    cin >> n;
    if (n <= 9)
    {
        cout << (n) * (n + 1) / 2 << nl;
    }
    else
    {
        vl vp;
        for (int i = 0; i < 16; i++)
        {
            vp.push_back(9 * bin_exp(10, i) * (i + 1));
        }
        auto it = upper_bound(vp.begin(), vp.end(), n) - vp.begin();
        it--;
        ll sum = 45 * (it + 1) * (bin_exp(10, it));
        ll k = (n - vp[it] + it + 2 - 1) / (it + 2);
        ll z = (bin_exp(10, it + 1));
        while(k--)
        {
            sum += (sumOfdigits(z));
            z++;
        }
        cout << sum << nl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}