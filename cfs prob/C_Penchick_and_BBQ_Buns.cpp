#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k,n) for(int i=k;i<n;i++)
#define nkinput() int n,k;cin>>n;cin>>k;
#define ninput() int n;cin>>n;
#define arrinput() vl arr(n);for(auto &c:arr) cin>>c;
#define forl for(int i=0;i<n;i++)
#define nl '\n'

// bool isEven(int n) {
//     return (n & 1) == 0;
// }

// bool isSorted(const vi& vec) {
//     for (size_t i = 0; i < vec.size() - 1; ++i) {
//         if (vec[i] > vec[i + 1]) {
//             return false;
//         }
//     }
//     return true;
// }

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
// }

// int power(int N, int M) {
//     int power = N, sum = 1;
//     if (N == 0) sum = 0;
//     while (M > 0) {
//         if ((M & 1) == 1) {
//             sum *= power;
//         }
//         power = power * power;
//         M = M >> 1;
//     }
//     return sum;
// }

// ll numofdiv(ll c) {
//     ll count = 0;
//     for (ll i = 1; i * i <= c; i++) {
//         if (c % i == 0) {
//             count++;
//             if (i != c / i) count++;
//         }
//     }
//     return count;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n;cin>>n;
        if(n&1) cout<<-1<<nl;
        else
        {
            for(int i=1;i<=n/2;i++)
            {
                cout<<i<<" "<<i<<" ";
            }
        }
        cout<<nl;
    }
    return 0;
}