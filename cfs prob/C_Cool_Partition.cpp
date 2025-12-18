// Qs: C_Cool_Partition
// Time: 09:45:31

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

int ans(vl &v, int idx,vl &totalUnique)
{
    if (idx < 0)
        return 0;
    map<int, int> mp;
    int unique = totalUnique[idx], r = idx, cnt = 0;
    set<int> st;
    while (r >= 0)
    {
        st.insert(v[r]);
        r--;
        if (st.size() == unique)
        {
            cnt++;
            break;
        }
    }
    return cnt + ans(v, r,totalUnique);
}
void solve()
{
    ll n;
    cin >> n;
    vin(v, n);
    vl totalUnique(n);
    ll unique = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp[v[i]] == 0)
            unique++;
        mp[v[i]]++;
        totalUnique[i] = unique;
    }
    cout << ans(v, n - 1,totalUnique) << nl;
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