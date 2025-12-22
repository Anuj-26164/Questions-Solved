// Qs: C_Concat_X_th
// Time: 18:05:39

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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<string> l;
    ll total = pow(n, k);
    for (ll mask = 0; mask < total; ++mask)
    {
        string s = "";
        ll tmp = mask;
        for (int i = 0; i < k; ++i)
        {
            int idx = tmp % n;
            s += v[idx];
            tmp /= n;
        }
        l.push_back(s);
    }

    sort(all(l));
    if (x <= l.size())
        cout << l[x - 1] << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    {
        solve();
    }
    return 0;
}