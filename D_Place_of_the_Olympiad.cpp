// Qs: D_Place_of_the_Olympiad
// Time: 04:47:11

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
bool pred(ll ma,ll n,ll m,ll k)
{
    __int128_t z=(m)/(ma+1);
    __int128_t total=(z*ma+m%(ma+1))*n;
    return total>=k;
}

void solve() {
    ll n,m,k;read3(n,m,k);
    ll lo=1,hi=1e9;
    ll mid;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        (pred(mid,n,m,k)?hi=mid:lo=mid+1);
    }
    if(pred(lo,n,m,k)) print(lo);
    else print(hi);
}
int main() {
    ll t;
    read(t);
    while (t--) {
        solve();
    }
    return 0;
}