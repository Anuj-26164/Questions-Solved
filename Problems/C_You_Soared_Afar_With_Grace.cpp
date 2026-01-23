// Qs: C_You_Soared_Afar_With_Grace
// Time: 14:29:05

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
#define MOD 1000000007LL
const ll INF = 4e18;
template <class T, class Container = vector<T>>
using maxheap = priority_queue<T, Container, less<T>>;
template <class T, class Container = vector<T>>
using minheap = priority_queue<T, Container, greater<T>>;
#define DP1(v, n) vector<long long> v((n) + 1)
#define DP2(v, n, m) vector<vector<long long>> v((n) + 1, vector<long long>((m) + 1))
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

#ifdef ONLINE_JUDGE
#include <chrono>
using namespace chrono;
#define TIMER_START auto __start = high_resolution_clock::now();
#define TIMER_END(msg)                                                                  \
    cerr << msg << ": "                                                                 \
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
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))

struct PairHash
{
    size_t operator()(const pair<int, int> &p) const
    {
        return ((uint64_t)p.first << 32) ^ p.second;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    f(i, 0, n) cin >> v[i].ff;
    f(i, 0, n) cin >> v[i].ss;
    unordered_map<pair<int, int>, int, PairHash> mp;
    unordered_map<int, int> mp1;
    f(i, 0, n)
    {
        mp[v[i]]++;
        mp1[v[i].ff] = i;
    }
    bool ok = true;
    f(i, 0, n)
    {
        int x = v[i].ff, y = v[i].ss;
        if (mp[{y, x}] == 0)
        {
            ok = false;
            break;
        }
    }
    int self = 0;
    for (auto &[p, cnt] : mp)
        if (p.first == p.second)
            self += cnt;

    if ((n % 2 == 0 && self > 0) ||
        (n % 2 == 1 && self != 1))
        ok = false;
    if (!ok)
        cout << -1 << nl;
    else
    {
        vector<pair<int, int>> ans;
        if (n & 1)
        {
            f(i, 1, n + 1)
            {
                if (mp[{i, i}] == 1 && mp1[i] != n / 2)
                {
                    int mid = n / 2;
                    int old = mp1[i];

                    ans.emplace_back(old + 1, mid + 1);

                    swap(v[mid], v[old]);
                    mp1[v[old].ff] = old;
                    mp1[v[mid].ff] = mid;

                    break;
                }
            }
        }
        int r = n - 1;
        for (int i = 0; i < n / 2; i++)
        {

            int j = mp1[v[i].ss];
            if (j != r)
            {
                ans.emplace_back(j + 1, r + 1);

                swap(v[j], v[r]);
                mp1[v[j].ff] = j;
                mp1[v[r].ff] = r;
            }
            r--;
        }
        cout << ans.size() << nl;
        for (auto [x, y] : ans)
        {
            cout << x << " " << y << nl;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    f(tt, 1, t + 1)
    {
        TIMER_START
        // cerr << "Case #" << tt << ": " << nl;
        solve();
        TIMER_END("Time")
    }
    return 0;
}