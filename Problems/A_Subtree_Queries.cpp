// Qs: A_Subtree_Queries
// Time: 16:17:54

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

int startt[200020], endt[200020], val[400040], v[200020];
int timer = 1;
void dfs(int node, int parent, vector<vector<int>> &adj)
{
    startt[node] = timer;
    val[timer++] = v[node];
    for (int child : adj[node])
    {
        if (child == parent)
            continue;
        dfs(child, node, adj);
    }
    endt[node] = timer;
    val[timer++] = v[node];
}

struct Fenwick
{
    int n;
    vector<int> bit;

    Fenwick(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, int delta)
    {
        while (i <= n)
        {
            bit[i] += delta;
            i += i & -i;
        }
    }

    int query(int i)
    {
        int sum = 0;
        while (i > 0)
        {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }

    int rangeQuery(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    f(i, 1, n + 1) cin >> v[i];
    vector<vector<int>> adj(n + 1);
    f(i, 1, n)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1, adj);
    Fenwick bit(2 * n + 10);
    for (int i = 1; i < timer; i++)
    {
        bit.update(i, val[i]);
    }
    while (q--)
    {
        int type, d;
        cin >> type >> d;
        if (type == 1)
        {
            int newd;
            cin >> newd;
            bit.update(startt[d], newd - v[d]);
            bit.update(endt[d], newd - v[d]);
            v[d] = newd;
        }
        else
        {
            cout << bit.rangeQuery(startt[d], endt[d]) / 2 << nl;
        }
    }
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