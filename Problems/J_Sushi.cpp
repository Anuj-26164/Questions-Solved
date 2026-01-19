// Qs: J_Sushi
// Time: 18:16:04

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

double dp[302][302][302];
void solve()
{
    int n;
    cin >> n;
    vin(v, n);
    // dp[x1][x2][x3] will store expected number of moves to eat x1 plates with 1 sushi, x2 with 2 ,x3 with 3
    //  therefore final answer will be dp[p1][p2][p3] where p1=number of plates with 1 sushi and so on,
    int p1 = 0, p2 = 0, p3 = 0;
    f(i, 0, n)
    {
        if (v[i] == 1)
            p1++;
        else if (v[i] == 2)
            p2++;
        else
            p3++;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 0; // base case
    // dp transition -> dp[x1][x2][x3] = ((x1/(x1+x2+x3))*(dp[x1-1][x2][x3])) + ((x2/(x1+x2+x3))*dp[x1+1][x2-1][x3]) +((x3/(x1+x2+x3))*dp[x1][x2+1][x3-1])

    for (int k = 0; k <= n; k++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int i = 0; i <= n; i++)
            {
                if (i >= 1)
                    dp[i][j][k] += (1.0 * i / (i + j + k)) * (dp[i - 1][j][k]);
                if (j >= 1)
                    dp[i][j][k] += (1.0 * j / (i + j + k)) * (dp[i + 1][j - 1][k]);
                if (k >= 1)
                    dp[i][j][k] += (1.0 * k / (i + j + k)) * (dp[i][j + 1][k - 1]);
                if (!(i == 0 && j == 0 && k == 0))
                    dp[i][j][k] += (1.0 * n / (i + j + k));
            }
        }
    }
    cout << fixed << setprecision(10) << dp[p1][p2][p3] << nl;
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
        // cerr << "Case #" << tt << ": "<<nl;
        solve();
    }
    return 0;
}