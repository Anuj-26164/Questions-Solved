// Qs: Chocolate
// Time: 14:14:20

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define int long long
#define ll long long
#define f(k,n) for(int i=k;i<n;i++)
#define nl '\n'
#define vin(v, n) vl v(n); for (int i = 0; i < n; i++) {cin>>v[i];}
#define vout(v, n) do { for (int i = 0; i < n; i++) cout << v[i] << " "; cout << "\n"; } while(0)
#define ff first
#define ss second
#define DP1(v, n) vector<long long> v((n)+1, -1)
#define DP2(v, n, m) vector<vector<long long>> v((n)+1, vector<long long>((m)+1, -1))
#define pll pair<long long,long long>
#define debug(x) cerr << #x << " = " << x << nl;

template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for(size_t i = 0; i < v.size(); i++) os << (i ? ", " : "") << v[i];
    return os << "]";
}

template<typename T, typename U>
ostream& operator<<(ostream &os, const pair<T,U> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
ostream& operator<<(ostream &os, const set<T> &s) {
    os << "{";
    bool f = true;
    for(auto &x : s) os << (f ? "" : ", ") << x, f = false;
    return os << "}";
}

template<typename T, typename U>
ostream& operator<<(ostream &os, const map<T,U> &m) {
    os << "{";
    bool f = true;
    for(auto &x : m) os << (f ? "" : ", ") << x, f = false;
    return os << "}";
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

//const int N = 1001, M = 11, MOD = 1e9 + 7;
//ll n, m, dp[M][N][N];
void solve() {
    int n, m;
    cin >> n >> m;
    vin(h, n-1);
    vin(v, m-1);
    int hm = 1, vm = 1;
    sort(all(h), greater<int>());
    sort(all(v), greater<int>());
    int ans = 0, l = 0, r = 0;
    while(l<n-1 && r<m-1)
    {
        if(h[l]>=v[r])
        {
            ans += hm * h[l];
            l++;
            vm++;
        }
        else
        {
            ans += vm * v[r];
            r++;
            hm++;
        }
    }
    while(l<n-1)
    {
        ans += hm * h[l];
        l++;
    }
    while(r<m-1)
    {
        ans += vm * v[r];
        r++;
    }
    cout << ans << nl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    ll t;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}