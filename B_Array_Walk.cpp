// Qs: B_Array_Walk
// Time: 14:25:50

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'
#define vin(v, n)               \
    vl v(n);                    \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> v[i];            \
    }
#define vout(v, n)                  \
    do                              \
    {                               \
        for (int i = 0; i < n; i++) \
            cout << v[i] << " ";    \
        cout << "\n";               \
    } while (0)
#define ff first
#define ss second
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

long long bin_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

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

// --------- Prefix and Suffix Sum Functions ----------
vl getPrefixSum(const vl &arr)
{
    int n = arr.size();
    vl prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}

vl getSuffixSum(const vl &arr)
{
    int n = arr.size();
    vl suffix(n);
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + arr[i];
    }
    return suffix;
}

// Range sum query using prefix sum (0-indexed)
ll rangeSum(const vl &prefix, int l, int r)
{
    if (l == 0)
        return prefix[r];
    return prefix[r] - prefix[l - 1];
}

bool isprime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
bool isValid(int x, int y, int n, int m, vector<vector<int>> &vis)
{
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
}

void yes()
{
    cout << "YES" << endl;
}

void no()
{
    cout << "NO" << endl;
}

#define msb(mask) (63 - __builtin_clzll(mask)) /// 0 -> -1
#define lsb(mask) __builtin_ctzll(mask)        /// 0 -> 64
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))

// const int N = 1001, M = 11, MOD = 1e9 + 7;
ll n, k, z;
vector<vector<vector<int>>> dp;

ll maxscore(int idx, int currleft, int z, vl &v)
{
    if (k == 0 || idx >= n || idx < 0)
        return 0;
    if (currleft)
    {
        if (idx < n - 1)
        {
            k--;
            return v[idx + 1] + maxscore(idx + 1, 0, z, v);
            k++;
        }
        else
            return 0;
    }
    else
    {
        ll l = 0, r = 0;
        if (idx > 0 && z > 0)
        {
            k--;
            l = v[idx - 1] + maxscore(idx - 1, 1, z - 1, v);
            k++;
        }
        else if (idx < n - 1)
        {
            k--;
            r = v[idx + 1] + maxscore(idx + 1, 0, z, v);
            k++;
        }
        return max(l, r);
    }
}
void solve()
{
    int n, k, z;
    cin >> n >> k >> z;
    int arr[n + 1];
    f(1, n + 1) cin >> arr[i];
    vl pref(n + 1);
    pref[0] = 0;
    f(1, n + 1)
    {
        pref[i] = pref[i - 1] + arr[i];
    }
    ll mx = pref[++k];
    for (int i = 1; i < k; i++)
    {
        for (int j = 1; j <= z; j++)
        {
            int p = k - j * 2;
            if (p < i)
                continue;
            mx = max(mx, pref[p] + j * (arr[i] + arr[i + 1]));
        }
    }
    cout << mx << endl;
    vi
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}