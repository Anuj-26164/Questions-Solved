// Qs: C_Mixture
// Time: 18:55:11

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
    cout << "Yes" << endl;
}

void no()
{
    cout << "No" << endl;
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
    ll k = s.size(); // should be 2^n - 1

    if (s[k - 1] != '0')
    {
        no(); // final state must be valid
        return;
    }

    vl dp(k + 1, 0);
    dp[0] = 1; // empty mask is valid

    for (int mask = 1; mask <= k; mask++)
    {
        if (s[mask - 1] == '1')
            continue;

        // Try to split this mask into two smaller valid parts
        for (int j = 0; j < n; j++)
        {
            int submask = mask ^ (1 << j); // turn off bit j
            if (submask < mask && (mask & (1 << j)))
            {
                if (dp[submask])
                {
                    dp[mask] = 1;
                    break;
                }
            }
        }
    }

    dp[k] ? yes() : no(); // can we reach the full mixture?
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