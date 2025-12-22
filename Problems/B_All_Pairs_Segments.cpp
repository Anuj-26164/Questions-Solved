#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n,q;cin>>n>>q;
        vl num(n),query(q);
        for(auto &c:num) cin>>c;
        for(auto &c:query) cin>>c;
        vl sol(n-3);
        for(int i=0;i<n-3;i++)
        {
            sol[i]=num[i+2]-num[i+1]
        }
        for(int i=0;i<q;i++)
        {
            ll sum=0;
            if(query[i]==n-1)
            {
                sum+=num[1]-num[0]+num[n-1]-num[n-2];
                cout<<sum<<" ";
            }
            if(query[i]==n+1)
            {
                
            }
        }
        
        
    }
    return 0;
}