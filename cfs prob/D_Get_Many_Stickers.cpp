// Qs: D_Get_Many_Stickers
// Time: 18:40:28

#include <bits/stdc++.h>
using namespace std;

#define read(x) scanf("%lld", &x) 
#define read2(x, y) scanf("%lld %lld", &x, &y)
#define read3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define print(x) printf("%lld\n", x)
#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k,n) for(int i=k;i<n;i++)
#define nl '\n'
#define vin(v, n) vl v(n); for (int i = 0; i < n; i++) read(v[i]);

// bool isprime(int n) {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (int i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }
//     return true;
long long nCr(int n, int r) {
       if (r > n) return 0;
             if (r > n - r) r = n - r;
             long long res = 1;
             for (int i = 1; i <= r; i++) {
                 res *= (n - r + i);
                 res /= i;
    }
              return res;
}

void yes() {
    cout << "YES" << endl;
}

void no() {
    cout << "NO" << endl;
}

#define msb(mask) (63-__builtin_clzll(mask))  /// 0 -> -1
#define lsb(mask) __builtin_ctzll(mask)  /// 0 -> 64
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask,bit) ((mask >> bit) & 1ll)
#define onbit(mask,bit) ((mask)|(1LL<<(bit)))
#define offbit(mask,bit) ((mask)&~(1LL<<(bit)))
#define changebit(mask,bit) ((mask)^(1LL<<bit))

ll countTrades(ll &n, ll give, ll receive)
{
    ll trades = 0;

    if (give <= receive)
    {
        // Infinite loop possible, simulate as much as possible
        trades = (n - give) / (give - receive) + 1;
        n += trades * (receive - give); // update n accordingly
    }
    else
    {
        while (n >= give)
        {
            ll t = n / give;
            trades += t;
            n = n - t * give + t * receive;
        }
    }

    return trades;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,pair<ll, ll>>> vp(m);
    for (int i = 0; i < m;i++)
    {
        ll x, y;
        cin >> x >> y;
        vp[i].second = {x, y};
        vp[i].first = abs(x-y);
    }
    sort(all(vp));
    int stickers = 0;
    for (int i = 0; i < m;i++)
    {
        int ai = vp[i].second.first;
        int bi = vp[i].second.second;
        int count = countTrades(n, ai, bi);
        stickers += count;
    }
    cout << stickers << nl;
}
int main() {
 {
        solve();
    }
    return 0;
}