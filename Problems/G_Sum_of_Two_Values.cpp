// Qs: G_Sum_of_Two_Values
// Time: 00:55:44

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define int long long
#define ll long long
#define f(i,k,n) for(int i=k;i<n;i++)
#define nl cout<<endl;
#define vin(v, n) vl v(n); for (int i = 0; i < n; i++) {cin>>v[i];}
#define vout(v,i,k,n) do { for (int i = k; i < n; i++) cout << v[i] << " "; cout << "\n"; } while(0)
#define ff first
#define ss second
#define MOD 1000000007LL
const ll INF = 4e18;
template<class T, class Container = vector<T>>
using maxheap = priority_queue<T, Container, less<T>>;
template<class T, class Container = vector<T>>
using minheap = priority_queue<T, Container, greater<T>>;
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

int msb(int mask) {
if (mask == 0) return -1;
return 63 - __builtin_clzll(mask);
}
#define lsb(mask) __builtin_ctzll(mask) /// 0 -> 64
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask,bit) ((mask >> bit) & 1ll)
#define onbit(mask,bit) ((mask)|(1LL<<(bit)))
#define offbit(mask,bit) ((mask)&~(1LL<<(bit)))
#define changebit(mask,bit) ((mask)^(1LL<<bit))

//const int N = 1001, M = 11, MOD = 1e9 + 7;
//ll n, m, dp[M][N][N];
void solve() {
    int n, target;
    cin >> n >> target;
    vector<pair<int, int>> v(n);
    f(i,0,n)
    {
        cin >> v[i].ff;
        v[i].ss = i;
    }
    sort(all(v));
    int l = 0, r = n - 1;
    while(l<r)
    {
        int sum = v[l].ff + v[r].ff;
        if(sum==target)
        {
            cout << v[l].ss + 1 << " " << v[r].ss + 1; 
            return ;
        }
        if(sum<target)
            l++;
        else
            r--;
    }
    cout << -1;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
     {
        solve();
    }
    return 0;
}