// Qs: B_Yet_Another_MEX_Problem
// Time: 20:58:01

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define int long long
#define ll long long
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
// ll n, m, dp[M][N][N];
int mex_of_array(const vector<int> &v)
{
    int n = v.size();
    vector<bool> seen(n + 1, false);

    for (int x : v)
    {
        if (x >= 0 && x <= n)
            seen[x] = true;
    }

    for (int i = 0; i <= n; i++)
    {
        if (!seen[i])
            return i;
    }
    return n + 1;
}

int max_mex_all_windows(const vector<int> &v, int k)
{
    int n = v.size();
    int len = n;

    if (len == 0)
        return 0;
    if (len > n)
        return mex_of_array(v);

    vector<int> freq(len + 1, 0);
    int ans = 0;

    for (int i = 0; i < len; i++)
    {
        if (v[i] <= len)
            freq[v[i]]++;
    }

    int mex = 0;
    while (mex <= len && freq[mex] > 0)
        mex++;

    ans = mex;

    for (int l = 1; l + len - 1 < n; l++)
    {
        int r = l + len - 1;

        if (v[l - 1] <= len)
        {
            freq[v[l - 1]]--;
            if (freq[v[l - 1]] == 0 && v[l - 1] < mex)
                mex = v[l - 1];
        }

        if (v[r] <= len)
        {
            freq[v[r]]++;
        }

        while (mex <= len && freq[mex] > 0)
            mex++;

        ans = max(ans, mex);
    }

    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    f(0, n)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << min(mex_of_array(v),k-1) << nl;
}
int32_t main()
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