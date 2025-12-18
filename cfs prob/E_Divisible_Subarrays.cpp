#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate GCD
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Function to calculate LCM
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Process updates
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        ll p;
        cin >> l >> r >> p;
        l--; r--; // Convert to 0-based indexing
        for (int i = l; i <= r; i++) {
            a[i] *= p;
        }
    }
    
    // Count valid subarrays
    int count = 0;
    for (int l = 0; l < n; l++) {
        ll product = 1;
        for (int r = l; r < n; r++) {
            product = lcm(product, a[r]); // Use LCM to handle overflow
            if (k % product == 0) {
                count++;
            }
            // If product becomes too large or exceeds k, break
            if (product > k) break;
        }
    }
    
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
