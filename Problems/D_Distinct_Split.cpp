// Qs: D_Distinct_Split
// Time: 18:21:00

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

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> pref(n), suff(n);
    set<char> seen;

    for (int i = 0; i < n; i++)
    {
        seen.insert(s[i]);
        pref[i] = seen.size();
    }

    seen.clear();

    for (int i = n - 1; i >= 0; i--)
    {
        seen.insert(s[i]);
        suff[i] = seen.size();
    }

    ll maxf = 0;
    for (int i = 0; i < n - 1; i++)
    {
        maxf = max(maxf, pref[i] + suff[i + 1]);
    }

    cout << maxf << nl;
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