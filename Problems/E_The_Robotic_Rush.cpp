// Qs: E_The_Robotic_Rush
// Time: 21:04:50

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

int findLeftTime(vector<int> &maxl, int dL)
{
    int l = 0, r = (int)maxl.size() - 1, ans = maxl.size();
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (maxl[mid] <= -dL)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    string s;
    cin >> s;

    vector<int> maxl(k), maxr(k);

    int netmove = 0, mn = 0, mx = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == 'R')
            netmove++;
        else
            netmove--;

        mn = min(mn, netmove);
        mx = max(mx, netmove);

        maxl[i] = mn;
        maxr[i] = mx;
    }

    vector<int> diff(k + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int death = k;

        // left me sabse paas
        int L = lower_bound(b.begin(), b.end(), a[i]) - b.begin() - 1;
        if (L >= 0)
        {
            int dL = a[i] - b[L];
            death = min(death, findLeftTime(maxl, dL));
        }

        //right me sabse paas
        int R = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        if (R < m)
        {
            int dR = b[R] - a[i];
            int tR = lower_bound(maxr.begin(), maxr.end(), dR) - maxr.begin();
            death = min(death, tR);
        }

        if (death < k)
            diff[death]--;
    }
    // debug(maxl);
    int alive = n;
    for (int i = 0; i < k; i++)
    {
        alive += diff[i];
        cout << alive << " ";
    }
    cout << nl;
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
        // cerr << "Case #" << tt << ": "<<nl;
        solve();
    }
    return 0;
}