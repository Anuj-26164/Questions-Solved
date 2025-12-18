#include <bits/stdc++.h>
using namespace std;

#define read(x) scanf("%lld", &x)
#define read2(x, y) scanf("%lld %lld", &x, &y)
#define print(x) printf("%lld\n", x)
#define ll long long int
#define vl vector<long long>

bool isValid(ll y, ll n, ll x, const vl &arr) {
    ll sum1 = 0;
    for (ll a : arr) {
        sum1 += min(a, y);  // Sum considering max height y
    }
    return (n * y - sum1) <= x;  // Check if extra water needed <= x
}

int main() {
    ll t;
    read(t);
    while (t--) {
        ll n, x;
        read2(n, x);
        vl arr(n);
        for (auto &c : arr) cin >> c;

        ll sum = accumulate(arr.begin(), arr.end(), 0LL);
        ll lo = 0, hi = (x + sum) / n;  // Initial search range

        while (lo < hi) {
            ll mid = (lo + hi + 1) / 2;  // Upper-biased mid
            if (isValid(mid, n, x, arr)) {
                lo = mid;  
            } else {
                hi = mid - 1;
            }
        }

        print(lo);
    }
    return 0;
}
