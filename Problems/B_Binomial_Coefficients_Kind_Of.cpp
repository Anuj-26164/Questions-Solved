#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ll long long int
#define forl for(int i=0;i<n;i++)
#define nl '\n'

//bool isEven(int n) {
//    return (n & 1) == 0;
//}

//bool isSorted(const vi& vec) {
//    for (size_t i = 0; i < vec.size() - 1; ++i) {
//        if (vec[i] > vec[i + 1]) {
//            return false;
//        }
//    }
//    return true;
//}

//bool isprime(int n) {
//    if (n <= 1) return false; // 0 and 1 are not prime
//    if (n <= 3) return true;  // 2 and 3 are prime
//    if (n % 2 == 0 || n % 3 == 0) return false;
//    for (int i = 5; i * i <= n; i += 6) {
//        if (n % i == 0 || n % (i + 2) == 0)
//            return false;
//    }
//    return true;
//}

//int power(int N, int M) {
//    int power = N, sum = 1;
//    if (N == 0) sum = 0;
//    while (M > 0) {
//        if ((M & 1) == 1) {
//            sum *= power;
//        }
//        power = power * power;
//        M = M >> 1;
//    }
//    return sum;
//}
const int MOD = 1e9 + 7;

long long modularExponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // If the current bit is 1
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // Square the base
        exp /= 2; // Move to the next bit
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    vi base(t);
    for(int i=0;i<t;i++)
    {
        cin>>base[i];
    }
    vi kk(t);
    for(int i=0;i<t;i++)
    {
        cin>>kk[i];
    }
    for(int i=0;i<t;i++)
    {
        cout<<modularExponentiation(2,kk[i],MOD)<<nl;
    }
    return 0;
}