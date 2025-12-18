// Qs: D_Match_Mod_Minimize_2
// Time: 18:33:12

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

ll solve_min_sum_mod(vector<ll> &A, vector<ll> &B, ll M)
{
    int N = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<ll>());

    ll sum = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += (A[i] + B[i]) % M;
    }
    return sum;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vin(a, n);
    vin(b, n);
    unordered_set<int> used; // store used values
    sort(a.begin(), a.end(), greater<int>());
    sort(all(b));
    for (int x : queries)
    {
        auto it = lower_bound(v.begin(), v.end(), x);

        while (it != v.end() && used.count(*it))
        {
            ++it; // skip used values
        }

        if (it == v.end())
        {
            cout << "No available value for query " << x << '\n';
        }
        else
        {
            cout << "Using: " << *it << '\n';
            used.insert(*it); // mark as used
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