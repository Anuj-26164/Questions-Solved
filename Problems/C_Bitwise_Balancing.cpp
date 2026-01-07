// Qs: C_Bitwise_Balancing
// Time: 19:26:58

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define int long long
#define ll long long
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'
#define vin(v, n)               \
    vl v(n);                    \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> v[i];            \
    }
#define vout(v, n)                  \
    do                              \
    {                               \
        for (int i = 0; i < n; i++) \
            cout << v[i] << " ";    \
        cout << "\n";               \
    } while (0)
#define ff first
#define ss second
#define DP1(v, n) vector<long long> v((n) + 1, -1)
#define DP2(v, n, m) vector<vector<long long>> v((n) + 1, vector<long long>((m) + 1, -1))
#define pll pair<long long, long long>
#define debug(x) cerr << #x << " = " << x << nl;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (size_t i = 0; i < v.size(); i++)
        os << (i ? ", " : "") << v[i];
    return os << "]";
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &s)
{
    os << "{";
    bool f = true;
    for (auto &x : s)
        os << (f ? "" : ", ") << x, f = false;
    return os << "}";
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &m)
{
    os << "{";
    bool f = true;
    for (auto &x : m)
        os << (f ? "" : ", ") << x, f = false;
    return os << "}";
}

void yes()
{
    cout << "YES" << endl;
}

void no()
{
    cout << "NO" << endl;
}

#define lsb(mask) __builtin_ctzll(mask)        /// 0 -> 64
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))

// const int N = 1001, M = 11, MOD = 1e9 + 7;
// ll n, m, dp[M][N][N];
int msb(int x)
{
    if (x == 0)
        return 0;
    return 31 - __builtin_clz(x);
}

void solve()
{
    int b, c, d;
    cin >> b >> c >> d;
    int x = max(msb(b), max(msb(c), msb(d)));
    vector<int> ans(x+1, 0);
    int carry = 0;
    for (int bit = 0; bit <= x; bit++)
    {
        int b1 = (b >> bit) & 1;
        int c1 = (c >> bit) & 1;
        int d1 = (d >> bit) & 1;

        bool ok = false;

        for (int x1 = 0; x1 <= 1; x1++)
        {
            int lhs = b1 | x1;
            int sum = (c1 & x1) + d1 + carry;
            int rhs = sum & 1;
            int newcarry = sum >> 1;

            if (lhs == rhs)
            {
                ans[bit] = x1;
                carry = newcarry;
                ok = true;
                break;
            }
        }

        if (!ok)
        {
            cout << -1 << nl;
            return;
        }
    }
    int f = 0;
    f(0,x+1)
    {
        f += (ans[i] * (1ll << i));
        if(f>(1ll<<61))
        {
            cout << -1 << nl;
            return;
        }
    }
    cout << f << nl;
}
int32_t main()
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