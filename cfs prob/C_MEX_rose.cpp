// Qs: C_MEX_rose
// Time: 20:36:16

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

#define msb(mask) (63 - __builtin_clzll(mask)) /// 0 -> -1
#define lsb(mask) __builtin_ctzll(mask)        /// 0 -> 64
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))

void solve()
{
    int n, k, avl = 0;
    cin >> n >> k;
    vin(v, n);
    map<int, int> mp;
    f(0, n)
    {
        mp[v[i]]++;
        if (v[i] >= k || (v[i] < k && mp[v[i]] > 1))
        {
            avl++;
        }
    }
    int cnt = 0;
    for (int i = 0; i <= k; i++)
    {
        if(i<k)
        {
            if (!mp.count(i))
            {
                if (mp[k])
                {
                    mp[k]--;
                }
                cnt++;
            }
        }
        else
        {
            if(mp.count(i))
            {
                cnt += mp[i];
            }
        }
    }
    cout << cnt << nl;
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