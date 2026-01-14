// Qs: C_Dungeon
// Time: 10:38:36

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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    minheap<int> pq;
    f(i, 0, n)
    {
        cin >> a[i];
        pq.push(a[i]);
    }
    vector<pair<int, int>> vp(m);

    f(i, 0, m) cin >> vp[i].ff;
    f(i, 0, m) cin >> vp[i].ss;
    sort(all(vp));
    int ans = 0;
    vector<int> c2;
    for (int i = 0; i < m;)
    {
        if (vp[i].ss == 0)
        {
            i++;
            continue;
        }

        if (pq.empty())
            break;

        int x = pq.top();
        pq.pop();

        if (x < vp[i].ff)
        {
            c2.push_back(x);
        }
        else
        {
            ans++;
            x = max(x, vp[i].ss);
            pq.push(x);
            i++;
        }
    }

    while (!pq.empty())
    {
        c2.push_back(pq.top());
        pq.pop();
    }
    sort(all(c2));
    for (int i = m - 1; i >= 0; i--)
    {
        if (vp[i].ss == 0)
        {
            if (c2.size() == 0)
                break;
            if (c2.back() >= vp[i].ff)
            {
                ans++;
                c2.pop_back();
            }
        }
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
    int tt = 1;
    while (t--)
    {
        // cerr << "Case #" << tt << ": " << nl;
        solve();
        tt++;
    }
    return 0;
}