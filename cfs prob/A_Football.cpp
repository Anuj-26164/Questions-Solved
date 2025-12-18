// Qs: A_Football
// CC: Anuj
// Time: 23:21:08

#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define forl for(int i=0;i<n;i++)
#define input(x,y) int x,y;cin>>x;cin>>y;
#define ninput() int n;cin>>n;
#define arrinput() vl arr(n);for(auto &c:arr) cin>>c;
#define forl for(int i=0;i<n;i++)
#define nl '\n'

bool isEven(int n) {
    return (n & 1) == 0;
}

//bool isSorted(const vi& vec) {
//    for (size_t i = 0; i < vec.size() - 1; ++i) {
//        if (vec[i] > vec[i + 1]) {
//            return false;
//        }
//    }
//    return true;
//}

//bool isprime(int n) {
//    if (n <= 1) return false;
//    if (n <= 3) return true;
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
//   return sum;
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool possible=false;
    string s;
    cin>>s;
    int count=0;
    if(s.size()<7) possible=false;
    else
    for(int i=0;i<s.size()-6;i++)
    {
        if(s[i]=='0' && s[i+1]=='0' && s[i+2]=='0' && s[i+3]=='0' && s[i+4]=='0' && s[i+5]=='0' && s[i+6]=='0')
        {
            possible=true;
            break;
        }
        if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='1' && s[i+3]=='1' && s[i+4]=='1' && s[i+5]=='1' && s[i+6]=='1')
        {
            possible=true;
            break;
        }
    }
    cout<<(possible?"YES":"NO");
    return 0;
}