// Qs: C_The_Nether
// Time: 21:29:04

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
#define ff first
#define ss second

// long long bin_exp(long long base, long long exp, long long mod) {
//     long long result = 1;
//     while (exp > 0) {
//         if (exp & 1) result = (result * base) % mod;
//         base = (base * base) % mod;
//         exp >>= 1;
//     }
//     return result;
// }

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
void printn(ll n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
}
void printans(vl &ans)
{
    f(0,ans.size())
    {
        cout << ans[i] << " ";
    }
}
void solve()
{
    ll n;
    cin >> n;

    vl longPath(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << "? " << i << " " << n << " ";
        printn(n);
        cout << endl;
        cout.flush();

        ll len;
        cin >> len;
        if (len == -1)
            return;
        longPath[i] = len;
    }

    vector<pair<ll, ll>> vp;
    for (int i = 1; i <= n; i++)
        vp.push_back({i, longPath[i]});
    sort(vp.begin(), vp.end(), [](auto &a, auto &b)
         { return a.second > b.second; });

    ll lpath = vp.empty() ? 0 : vp[0].second;

    vl ans;
    vl visited(n + 1, 0);

    for (auto [a, b] : vp)
    {
        if (b == lpath && ans.empty())
        {
            ans.push_back(a);
            visited[a] = 1;
        }
    }

    for (auto [a, b] : vp)
    {
        if (!visited[a])
        {
            cout << "? " << ans.back() << " " << 2 << " " << ans.back() << " " << a << endl;
            cout.flush();

            ll x;
            cin >> x;
            if (x == -1)
                return;
            if (x != 1)
            {
                ans.push_back(a);
                visited[a] = 1;
            }
        }
    }

    cout << "! " << ans.size() << " ";
    printans(ans);
    cout << endl;
    cout.flush();
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