// Qs: G_GCD_on_a_grid
// Time: 02:00:44

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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    mat.assign(n, vector<int>(m));
    f(i, 0, n) f(j, 0, m) cin >> mat[i][j];
    int x = __gcd(mat[0][0], mat[n - 1][m - 1]);
    set<int> div;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            div.insert(i);
            div.insert(x / i);
        }
    }
    // dp[i][j] = is it possible to reach (i,j) by down and right movements and curr[i][j]=1
    vector<vector<bool>> curr(n, vector<bool>(m));
    vector<vector<bool>> dp(n, vector<bool>(m));
    int ans = 1;
    for (auto &y : div)
    {
        curr.assign(n, vector<bool>(m, false));
        f(i, 0, n) f(j, 0, m) if (mat[i][j] % y == 0) curr[i][j] = 1;
        else curr[i][j] = 0;

        dp.assign(n, vector<bool>(m, false));

        dp[0][0] = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (curr[i][j] && dp[i][j])
                {
                    if (i + 1 < n && curr[i + 1][j])
                        dp[i + 1][j] = 1;
                    if (j + 1 < m && curr[i][j + 1])
                        dp[i][j + 1] = 1;
                }
            }
        }
        if (dp[n - 1][m - 1])
            ans = y;
    }
    cout << ans << nl;
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