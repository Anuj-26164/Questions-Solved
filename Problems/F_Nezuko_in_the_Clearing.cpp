// Qs: F_Nezuko_in_the_Clearing
// Time: 21:10:49

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define ll long long int
#define f(k,n) for(int i=k;i<n;i++)
#define nl '\n'
#define vin(v, n) vl v(n); for (int i = 0; i < n; i++) {cin>>v[i];}
#define vout(v, n) do { for (int i = 0; i < n; i++) cout << v[i] << " "; cout << "\n"; } while(0)
#define ff first
#define ss second
#define pll pair<long long,long long>
// --------- Priority Queue Templates ----------
template <typename T>
using max_heap = priority_queue<T>;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;



#define msb(mask) (63-__builtin_clzll(mask))  /// 0 -> -1
#define lsb(mask) __builtin_ctzll(mask)  /// 0 -> 64
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask,bit) ((mask >> bit) & 1ll)
#define onbit(mask,bit) ((mask)|(1LL<<(bit)))
#define offbit(mask,bit) ((mask)&~(1LL<<(bit)))
#define changebit(mask,bit) ((mask)^(1LL<<bit))

void solve() {
    ll h, d;
    cin >> h >> d;
    ll moves = 0, pos = 0;
    while(pos<d)
    {
        
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    ll t;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}