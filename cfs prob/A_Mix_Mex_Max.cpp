// Qs: A_Mix_Mex_Max
// Time: 20:14:03

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

// bool isprime(int n) {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (int i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }
//     return true;
long long nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r > n - r)
        r = n - r;
    long long res = 1;
    for (int i = 1; i <= r; i++)
    {
        res *= (n - r + i);
        res /= i;
    }
    return res;
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

bool cond(const vector<ll> &v)
{
    int n = v.size();

    for (int i = 0; i <= n - 3; i++)
    {
        set<int> s = {v[i], v[i + 1], v[i + 2]};
        int mex = 0;
        while (s.count(mex))
            mex++;

        int triplet_max = max({v[i], v[i + 1], v[i + 2]});
        int triplet_min = min({v[i], v[i + 1], v[i + 2]});

        if (mex != (triplet_max - triplet_min))
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    ll n;
    cin >> n;
    vin(v, n);
    bool hasZero = (find(v.begin(), v.end(), 0) != v.end());
    if (hasZero)
    {
        no();
    }
    else
    {
        int nonneg = -1;
        f(0, n)
        {
            if (v[i] != -1)
            {
                nonneg = i;
                break;
            }
        }
        bool poss = true;
        if (v[0] == -1)
        {
            if(nonneg==-1)
            {
                v[0] = 5;
            }
            else
            {
                v[0] = v[nonneg];
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (v[i] == -1)
                v[i] = v[i - 1];
        }
        if (cond(v))
            yes();
        else
            no();
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