#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define read(x) scanf("%lld", &x)
#define read2(x, y) scanf("%lld %lld", &x, &y)
#define print(x) printf("%lld\n", x)

int main() {
    ll n, s;
    read2(n, s);
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) read(a[i]);
    ll l = 0, sum = 0, max_len = 0;
    for (ll r = 0; r < n; r++) {
        sum += a[r];
        while (sum > s) {  
            sum -= a[l];
            l++;
        }
        max_len = max(max_len, r - l + 1);
    }
    print(max_len);
    return 0;
}
