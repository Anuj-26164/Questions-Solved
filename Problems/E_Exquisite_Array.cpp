// Qs: E_Exquisite_Array
// Time: 00:44:44

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

// --------- DSU by Size Template ----------
class DSU
{
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unite(int x, int y)
    {
        int px = find(x), py = find(y);
        if (px == py)
            return false;

        if (size[px] < size[py])
            swap(px, py);
        parent[py] = px;
        size[px] += size[py];
        return true;
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }

    int getSize(int x)
    {
        return size[find(x)];
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    if (n == 1)
    {
        cout << 0 << "\n";
        return;
    }

    // Step 1: adjdiff
    vector<int> adjdiff(n - 1);
    for (int i = 0; i < n - 1; i++)
        adjdiff[i] = abs(v[i] - v[i + 1]);

    // Step 2: sort indices by adjdiff descending
    vector<int> idx(n - 1);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&](int a, int b)
         {
             return adjdiff[a] > adjdiff[b];
         });

    vector<long long> ans(n, 0);
    ans[1] = 1LL * n * (n - 1) / 2; // k = 1

    DSU dsu(n - 1);
    vector<bool> active(n - 1, false);

    long long cur = 0; // current total contribution
    int p = 0;

    // Step 3: process k from high to low
    for (int k = n - 1; k >= 2; k--)
    {
        while (p < n - 1 && adjdiff[idx[p]] >= k)
        {
            int i = idx[p++];
            active[i] = true;

            // new segment of length 1
            cur += 1;

            // merge with left
            if (i > 0 && active[i - 1])
            {
                int a = dsu.getSize(i);
                int b = dsu.getSize(i - 1);
                cur -= 1LL * a * (a + 1) / 2;
                cur -= 1LL * b * (b + 1) / 2;
                dsu.unite(i, i - 1);
                int c = dsu.getSize(i);
                cur += 1LL * c * (c + 1) / 2;
            }

            // merge with right
            if (i + 1 < n - 1 && active[i + 1])
            {
                int a = dsu.getSize(i);
                int b = dsu.getSize(i + 1);
                cur -= 1LL * a * (a + 1) / 2;
                cur -= 1LL * b * (b + 1) / 2;
                dsu.unite(i, i + 1);
                int c = dsu.getSize(i);
                cur += 1LL * c * (c + 1) / 2;
            }
        }
        ans[k] = cur;
    }

    for (int k = 1; k <= n - 1; k++)
        cout << ans[k] << " ";
    cout << "\n";
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
        // cerr << "Case #" << tt << ": ";
        solve();
        tt++;
    }
    return 0;
}