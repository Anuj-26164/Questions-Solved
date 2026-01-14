// Qs: C_Light_Switches
// Time: 21:11:25

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
#define vout(v, i, k, n)            \
    do                              \
    {                               \
        for (int i = k; i < n; i++) \
            cout << v[i] << " ";    \
        cout << "\n";               \
    } while (0)
#define ff first
#define ss second
#define MOD 1000000007LL
const ll INF = 4e18;
template <class T, class Container = vector<T>>
using maxheap = priority_queue<T, Container, less<T>>;
template <class T, class Container = vector<T>>
using minheap = priority_queue<T, Container, greater<T>>;
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

int msb(int mask)
{
    if (mask == 0)
        return -1;
    return 63 - __builtin_clzll(mask);
}
#define lsb(mask) __builtin_ctzll(mask)
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;

    long long lo = *max_element(a.begin(), a.end());
    long long hi = lo + k - 1;

    // we only need indices [0 .. k]
    vector<int> diff(k + 2, 0);

    // skip the maximum element (it always covers [lo, hi])
    for (int i = 0; i < n; i++)
    {
        if (a[i] == lo)
            continue;

        long long min_x =
            (lo - (k - 1) - a[i] + 2LL * k - 1) / (2LL * k); // ceil
        long long max_x =
            (hi - a[i]) / (2LL * k); // floor

        bool ok = false;

        for (long long x = min_x; x <= max_x; x++)
        {
            long long L = a[i] + 2LL * k * x;
            long long R = L + k - 1;

            if (R < lo || L > hi)
                continue;

            L = max(L, lo);
            R = min(R, hi);

            diff[L - lo]++;
            diff[R - lo + 1]--;
            ok = true;
        }

        if (!ok)
        {
            cout << -1 << '\n';
            return;
        }
    }

    int cur = 0;
    for (int i = 0; i < k; i++)
    {
        cur += diff[i];
        if (cur == n - 1)
        {
            cout << lo + i << '\n';
            return;
        }
    }

    cout << -1 << '\n';
    return;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    int tt = 1;
    while (t--)
    {
        // cerr << "Case #" << tt << ": " << nl;
        solve();
        tt++;
    }
    return 0;
}