// Qs: C_Superultra_s_Favorite_Permutation
// Time: 20:00:46

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define ll long long int
#define f(k,n) for(int i=k;i<n;i++)
#define nl '\n'
#define vin(v, n) vl v(n); for (int i = 0; i < n; i++) {cin>>v[i];}

//long long bin_exp(long long base, long long exp, long long mod) {
//    long long result = 1;
//    while (exp > 0) {
//        if (exp & 1) result = (result * base) % mod;
//        base = (base * base) % mod;
//        exp >>= 1;
//    }
//    return result;
//}

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

void solve() {
    ll n;
    cin >> n;
    if(n<=4)
        cout << -1 << nl;
    else
    {
        if(n==5)
            cout << 2 << " " << 4 << " " << 5 << " " << " " << 3 << " " << 1 << nl;
        else
        {
            vl even, odd;
            for (int i = 1; i <= n;i++)
            {
                if(i%2&&i!=3)
                    odd.push_back(i);
                else if(i%2==0&&i!=6)
                    even.push_back(i);
            }
            f(0,odd.size())
            {
                cout << odd[i] << " ";
            }
            cout << 3 << " " << 6 << " ";
            f(0, even.size())
            {
                cout << even[i] << " ";
            }
            cout << nl;
        }
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