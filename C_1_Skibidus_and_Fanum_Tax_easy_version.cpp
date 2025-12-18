// Qs: C_1_Skibidus_and_Fanum_Tax_easy_version
// Time: 10:25:58

#include <bits/stdc++.h>
using namespace std;

#define read(x) scanf("%lld", &x) 
#define read2(x, y) scanf("%lld %lld", &x, &y)
#define read3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define print(x) printf("%lld\n", x)
#define vl vector<long long>
#define all(x) begin(x), end(x)
#define pb push_back
#define minval -2147483648
#define maxval 2147483647
#define ll long long int
#define f(k,n) for(int i=k;i<n;i++)
#define nl '\n'
#define vin(v, n) vl v(n); for (int i = 0; i < n; i++) cin >> v[i];

// bool isprime(int n) {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (int i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }
//     return true;

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

int main() {
    ll t;
    read(t);
    while (t--) {
        ll n, m;
        read2(n, m);
        vin(a, n);
        ll b;
        read(b);
        bool flag=true;
        a[0]=min(a[0],b-a[0]);
        f(1,n)
        {
            if(a[i]>b-a[i])
            {
                if(b-a[i]>=a[i-1]) a[i]=b-a[i];
            }
            else
            {
                if(a[i-1]>a[i]) a[i]=b-a[i];
            }
            if(a[i-1]>a[i])
            {
                flag=false;break;
            }
        }
        (flag?yes():no());
    }
    return 0;
}