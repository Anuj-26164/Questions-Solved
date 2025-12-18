// Qs: A_Brogramming_Contest
// Time: 20:08:40

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k,n) for(int i=k;i<n;i++)
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
        int n;cin>>n;
        string s;cin>>s;
        bool occuredzero=false;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                occuredzero=true;
            }
            if(s[i]=='1' && occuredzero==true)
            {
                
            }
            
        }
    }
    return 0;
}