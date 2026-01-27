// Qs: G_Paths_in_a_Tree
// Time: 00:04:18

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

void dfs(int node, int parent, vector<int> &dp, vector<vector<int>> &adj)
{
    // action on vertex when entering
    dp.emplace_back(node); // example initialization (change as needed)

    for (int child : adj[node])
    {
        if (child == parent)
            continue;

        // action before going to child
        dfs(child, node, dp, adj);

        // action after returning from child
    }

    // action on vertex before exiting
}

void ask(int x, int y)
{
    cout << "?" << " " << x + 1 << " " << y + 1 << nl;
}
void ans(int x)
{
    cout << "!" << " " << x + 1 << nl;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dp;
    dfs(0, -1, dp, adj);
    int response;
    for (int i = 0; i + 1 < n; i += 2)
    {
        ask(dp[i], dp[i + 1]);
        cin >> response;
        if (response)
        {
            ask(dp[i], dp[i]);
            cin >> response;
            if (response)
                ans(dp[i]);
            else
                ans(dp[i + 1]);
            return;
        }
    }
    ans(dp[n - 1]);
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
        // TIMER_START
        //  cout << "Case #" << tt << ": "<<nl;
        solve();
        // TIMER_END("Time")
    }
    return 0;
}