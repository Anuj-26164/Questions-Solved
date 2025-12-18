#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    ll L = lcm(a * b, c * d); // LCM of both values

    // Smallest x in range [l1, r1]
    ll x = l1;  

    // Smallest y in range [l2, r2]
    ll y = l2;  

    // If x * y is a multiple of L, return x + y
    if ((x * y) % L == 0) {
        cout << x + y << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
