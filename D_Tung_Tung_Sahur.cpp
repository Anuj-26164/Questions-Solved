// Qs: D_Tung_Tung_Sahur
// Time: 08:04:59

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
#define lsb(mask) __builtin_ctzll(mask)        /// 0 -> 64p
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))

void solve()
{
    string ip, op;
    cin >> ip >> op;
    int n = ip.size();
    int m = op.size();
    vector<pair<char, int>> vip, vop;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        char c = ip[i];
        while (i + 1 < n && ip[i + 1] == c)
        {
            cnt++;
            i++;
        }
        vip.push_back({c, cnt * 2});
    }
    for (int i = 0; i < m; i++)
    {
        int cnt = 1;
        char c = op[i];
        while (i + 1 < m && op[i + 1] == c)
        {
            cnt++;
            i++;
        }
        vop.push_back({c, cnt});
    }
    // for (auto [a, b] : vip)
    //     cout << a << b<<" ";
    // cout << nl;

    // for (auto [a, b] : vop)
    //     cout << a << b << " ";
    
    if (vip.size() != vop.size())
        no();
    else
    {
        for (int j = 0; j < vip.size(); j++)
        {
            if (vip[j].ff != vop[j].ff || vop[j].ss > vip[j].ss || vop[j].ss < (vip[j].ss)/2)
            {
                no();
                return;
            }
        }
        yes();
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