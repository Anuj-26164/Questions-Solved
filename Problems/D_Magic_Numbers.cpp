// Qs: D_Magic_Numbers
// Time: 14:23:17

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define int long long
#define ll long long
#define f(i, k, n) for (int i = k; i < n; i++)
#define nl endl
#define vin(v, n)               \
    vl v(n);                    \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> v[i];            \
    }
#define vout(v, k, n)               \
    do                              \
    {                               \
        for (int i = k; i < n; i++) \
            cout << v[i] << " ";    \
        cout << "\n";               \
    } while (0)
#define ff first
#define ss second
#define rn return
#define MOD 1000000007LL
const ll INF = 4e18;
template <class T, class Container = vector<T>>
using maxheap = priority_queue<T, Container, less<T>>;
template <class T, class Container = vector<T>>
using minheap = priority_queue<T, Container, greater<T>>;
#define DP1(v, n) vector<long long> v((n) + 1)
#define DP2(v, n, m) vector<vector<long long>> v((n) + 1, vector<long long>((m) + 1))
#define pll pair<long long, long long>
#define d(x) cout << #x << " = " << x << nl;

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

template <typename T, typename U>
ostream &operator<<(ostream &os, const vector<pair<T, U>> &v)
{
    os << "[";
    bool f = true;
    for (auto &x : v)
        os << (f ? "" : ", ") << x, f = false;
    return os << "]";
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

#ifdef ONLINE_JUDGE
#include <chrono>
using namespace chrono;
#define TIMER_START auto __start = high_resolution_clock::now();
#define TIMER_END(msg)                                                                  \
    cout << msg << ": "                                                                 \
         << duration_cast<milliseconds>(high_resolution_clock::now() - __start).count() \
         << " ms\n";
#else
#define TIMER_START
#define TIMER_END(msg)
#endif

void yes()
{
    cout << "YES" << endl;
}

void no()
{
    cout << "NO" << endl;
}

int msb(int mask)
{
    if (mask == 0)
        return -1;
    return 63 - __builtin_clzll(mask);
}
#define lsb(mask) __builtin_ctzll(mask)
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) |= (1LL << (bit)))
#define offbit(mask, bit) ((mask) &= ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^= (1LL << bit))
#define togglebit(mask, bit) ((mask) ^= (1LL << (bit)))

int m, d;
string a, b;
int dp[2002][2][2002];
int cnt(int pos, bool tight, int rem, string &a)
{
    if (pos == a.size())
        return (rem == 0) ? 1 : 0;
    if (dp[pos][tight][rem] != -1)
        return dp[pos][tight][rem];
    int lim, res = 0, newrem;
    if (tight)
        lim = a[pos] - '0';
    else
        lim = 9;
    for (int dig = 0; dig <= lim; dig++)
    {
        bool t = tight && (dig == lim);
        if ((pos & 1)) // pos is odd I can take only take dig=d
        {
            if (dig == d)
            {
                newrem = (rem * 10 + dig) % m;
                res = (res + cnt(pos + 1, t, newrem, a)) % MOD; // take d
            }
        }
        else // pos is odd I can take any dig<=lim except 'd'
        {
            if (dig != d)
            {
                newrem = (rem * 10 + dig) % m;
                res = (res + cnt(pos + 1, t, newrem, a)) % MOD;
            }
        }
    }
    return dp[pos][tight][rem] = res;
}
void solve()
{
    // call a number d-magic if digit d appears in decimal presentation of the number on even positions and nowhere else.
    // At which position we are, if the number has already become smaller than b and the frequency of digit d till now.
    cin >> m >> d;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    a.back() -= 1;
    int r = cnt(0, 1, 0, b);
    memset(dp, -1, sizeof(dp));
    int l = cnt(0, 1, 0, a);
    cout<< (r - l + MOD) % MOD;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    f(tt, 1, t + 1)
    {
        // TIMER_START
        //  cout << "Case #" << tt << ": "<<nl;
        solve();
        // TIMER_END("Time")
    }
    return 0;
}