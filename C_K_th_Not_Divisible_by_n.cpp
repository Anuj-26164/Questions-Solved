#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define read(x) scanf("%lld", &x)
#define print(x) printf("%lld\n", x)

ll pred(ll num, ll k, ll n) {
    ll z = num / n;
    return (num - z < k) ? 1 : (num - z > k ? 2 : 3);
}

int main() {
    ll t;
    read(t);
    while (t--) {
        ll n, k;
        read(n); read(k);

        ll lo = 1, hi = 1e10, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (pred(mid, k, n) == 1) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        print(lo);
    }
    return 0;
}
