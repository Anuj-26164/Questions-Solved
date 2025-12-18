// Qs: B_Abraham_s_Great_Escape
// Time: 12:05:26

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
#define pll pair<long long, long long>
// --------- Priority Queue Templates ----------
template <typename T>
using max_heap = priority_queue<T>;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

bool isEven(ll n)
{
    return (n & 1) == 0;
}

bool isSorted(const vl &vec)
{
    for (size_t i = 0; i < vec.size() - 1; ++i)
    {
        if (vec[i] > vec[i + 1])
        {
            return false;
        }
    }
    return true;
}

//--------- Grid movement (4-dir) ----------
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

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

void solve()
{
    ll n, k;
    cin >> n >> k;
    if (k == (n * n - 1))
        no();
    else
    {
        k = n * n - k;
        yes();
        vector<vector<char>> grid(n, vector<char>(n, 'D'));
        int z = k / n;
        int rows = 0;
        for (int i = 1; i <= z; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                {
                    grid[rows][j] = 'R';
                }
                else
                {
                    grid[rows][j] = 'L';
                }
            }
            rows++;
        }
        if(rows<n)
        {
            k = k % n;
            if (k == 1)
                grid[rows][0] = 'U';
            else
                grid[rows][0] = 'R';
            for (int i = 1; i < k; i++)
            {
                grid[rows][i] = 'L';
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j];
            }
            cout << nl;
        }
    }
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