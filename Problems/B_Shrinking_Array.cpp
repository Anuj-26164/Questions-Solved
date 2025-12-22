// Qs: B_Shrinking_Array
// Time: 20:02:26

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define ll long long int
#define f(k,n) for(int i=k;i<n;i++)
#define nl '\n'
#define vin(v, n) vl v(n); for (int i = 0; i < n; i++) {cin>>v[i];}

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

bool issorted(const vector<ll> &v)
{
    if (v.size() < 2)
        return true;

    bool increasing = v[1] > v[0];
    bool decreasing = v[1] < v[0];

    if (!increasing && !decreasing)
        return false;

    for (int i = 1; i < v.size(); ++i)
    {
        int diff = abs(v[i] - v[i - 1]);
        if (diff < 2)
            return false;
        if (increasing && v[i] <= v[i - 1])
            return false;
        if (decreasing && v[i] >= v[i - 1])
            return false;
    }

    return true;
}

bool isValid(const vector<ll> &a)
{
    for (int i = 0; i + 1 < a.size(); ++i)
    {
        if (abs(a[i] - a[i + 1]) <= 1)
            return true;
    }
    return false;
}

void solve() {
    ll n;
    cin >> n;
    vin(v, n);
    if(isValid(v))
    {
        cout << 0;
    }
    else
    {bool poss = true;
    if(issorted(v))
        poss = false;
    poss ? cout << 1 : cout << -1;}
    cout << nl;
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