// Qs: Mixing_Liquids
// Time: 20:13:24

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


bool isEven(ll n) {
     return (n & 1) == 0;
 }

 bool isSorted(const vl& vec) {
     for (size_t i = 0; i < vec.size() - 1; ++i) {
         if (vec[i] > vec[i + 1]) {
             return false;
         }
     }
     return true;
 }

//--------- Grid movement (4-dir) ----------
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

long long bin_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

bool isprime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
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
bool isValid(int x, int y, int n, int m, vector<vector<int>> &vis) {
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
}

int power(int N, int M) {
    int power = N, sum = 1;
    if (N == 0) sum = 0;
    while (M > 0) {
        if ((M & 1) == 1) {
            sum *= power;
        }
        power = power * power;
        M = M >> 1;
    }
    return sum;
}

int binary_search(vl &arr, ll k) {
    ll lo = 0, hi = arr.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == k) 
            return mid;  
        else if (arr[mid] < k) 
            lo = mid + 1;  
        else 
            hi = mid - 1;  
    }
    return -1;  
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

void solve() {
    ll n, k;
    cin >> n >> k;
    ll z = max(n, k);
    ll y = min(n, k);
    cout << z / y << nl;
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