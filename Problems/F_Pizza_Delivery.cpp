// Qs: F_Pizza_Delivery
// Time: 21:42:37

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
    int n, Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;

    vector<pair<int, int>> vp(n);
    f(i, 0, n) cin >> vp[i].ff;
    f(i, 0, n) cin >> vp[i].ss;
    map<int, vector<int>> mp;

    f(i, 0, n) mp[vp[i].ff].emplace_back(vp[i].ss);
    int curl = -1, curh = -1, prevl = -1, prevh = -1, ans = Bx - Ax;
    // curl defined as min delivery time if last delivery at prev x is at lowest point
    // curh defined as min delivery time if last delivery at prev x is at highest point

    for (auto p = mp.begin(); p != mp.end(); p++)
    {
        sort(all((*p).ss));
        int x = (*p).ss.size();
        int y1 = (*p).ss[0], y2 = (*p).ss[x - 1];
        if (prevl == -1 && prevh == -1) // base case
        {
            prevl = abs(y2 - Ay) + abs(y1 - y2);
            prevh = abs(y1 - Ay) + abs(y1 - y2);
        }
        else
        {
            auto x = p;
            x--;
            int ylp = (*x).ss[0], yhp = (*x).ss[(*x).ss.size() - 1];
            curl = min(prevl + abs(ylp - y2) + abs(y2 - y1), prevh + abs(yhp - y2) + abs(y2 - y1));
            curh = min(prevl + abs(ylp - y1) + abs(y2 - y1), prevh + abs(yhp - y1) + abs(y2 - y1));
            prevl = curl;
            prevh = curh;
        }
    }
    // final go home
    auto it = mp.end();
    it--;
    int lowY = (*it).ss[0];
    int highY = (*it).ss[(*it).ss.size() - 1];

    ans += min(
        prevl + abs(lowY - By),
        prevh + abs(highY - By));

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