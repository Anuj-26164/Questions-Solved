// Qs: C_1_No_Cost_Too_Great_Easy_Version
// Time: 23:13:45

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

int spf[200020];
void build_spf()
{
    for (int i = 1; i <= 200010; i++)
        spf[i] = i;
    for (int i = 2; i * i <= 200010; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= 200010; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++)
        cin >> vp[i].first;
    for (int i = 0; i < n; i++)
        cin >> vp[i].second;

    // sort by cost
    sort(vp.begin(), vp.end(), [](auto &x, auto &y)
         { return x.second < y.second; });

    // conflict check
    set<int> cnt;
    for (int i = 0; i < n; i++)
    {
        set<int> s;
        int x = vp[i].first;
        while (x > 1)
        {
            s.insert(spf[x]);
            x /= spf[x];
        }
        for (auto p : s)
        {
            if (cnt.count(p))
            {
                cout << 0 << nl;
                return;
            }
            cnt.insert(p);
        }
    }

    // CASE 1: ≤ 1 operation
    long long mincost = vp[0].second + vp[1].second;

    // one operation
    for (int i = 0; i < n; i++)
    {
        int x = vp[i].first + 1;
        set<int> s;
        while (x > 1)
        {
            s.insert(spf[x]);
            x /= spf[x];
        }
        for (auto p : s)
        {
            if (cnt.count(p))
            {
                mincost = min(mincost, (long long)vp[i].second);
                break;
            }
        }
    }

    // CASE 2: multi-operations only on cheapest
    int a1 = vp[0].first;
    long long b1 = vp[0].second;

    set<int> other_primes;
    for (int i = 1; i < n; i++)
    {
        int x = vp[i].first;
        while (x > 1)
        {
            other_primes.insert(spf[x]);
            x /= spf[x];
        }
    }

    for (auto p : other_primes)
    {
        int need = (p - a1 % p) % p;
        mincost = min(mincost, (long long)need * b1);
    }

    cout << mincost << nl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    int tt = 1;
    build_spf();
    while (t--)
    {
        // cerr << "Case #" << tt << ": ";<<nl
        solve();
        tt++;
    }
    return 0;
}