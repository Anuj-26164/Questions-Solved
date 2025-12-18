#include <bits/stdc++.h>
using namespace std;

#define read(x) scanf("%lld", &x) 
#define read2(x, y) scanf("%lld %lld", &x, &y)
#define print(x) printf("%lld\n", x)
#define vl vector<long long>
#define ll long long int
#define vin(v, n) vl v(n); for (int i = 0; i < n; i++) read(v[i]);

int main() {
    ll n, s;
    read2(n, s);
    vin(a, n);
    
    ll l = 0, x = 0, len = n + 1;
    for (int r = 0; r < n; r++) {
        x += a[r];
        while (x >= s) { 
            len = min(len, r - l + 1);
            x -= a[l++];
        }
    }

    print(len == (n + 1) ? -1 : len);
    return 0;
}
