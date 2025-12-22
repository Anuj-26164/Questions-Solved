#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Checks if n has any prime factor less than p
bool hasSmallerPrimeFactor(ll n, ll p) {
    if (n == 1) return false;
    if (p > 2 && n % 2 == 0) return true;
    
    ll bound = min(p, (ll)sqrt(n) + 1);
    for (ll i = 3; i < bound; i += 2) {
        if (n % i == 0) return true;
    }
    return false;
}

ll countValidKeys(ll l, ll r, ll p) {
    // If p is not prime, result will be 0
    if (p > 2 && p % 2 == 0) return 0;
    if (p > 3 && p % 3 == 0) return 0;
    
    // Find first and last multiples of p in range
    ll first = (l + p - 1) / p * p;
    ll last = r / p * p;
    
    if (first > r) return 0;
    
    ll count = 0;
    // Handle powers of p separately
    ll power = p;
    while (power <= r) {
        if (power >= l) count++;
        if (power > r/p) break;
        power *= p;
    }
    
    // Handle small numbers separately to avoid overflow
    if (last <= 1000000) {
        for (ll i = first; i <= last; i += p) {
            if (i/p == 1 || !hasSmallerPrimeFactor(i/p, p)) count++;
        }
        return count;
    }
    
    // For large numbers, use mathematical properties
    // All numbers divisible by p whose other factor has no prime less than p
    ll numbers = (last - first) / p + 1;
    
    // Subtract numbers that have smaller prime factors
    ll subtract = 0;
    for (ll i = 2; i < p && i * i <= r/p; i++) {
        if (i == 2 || !hasSmallerPrimeFactor(i, i)) {
            ll multiples = r/(p*i) - (l-1)/(p*i);
            subtract += multiples;
        }
    }
    
    return count + numbers - subtract;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll l, r, p;
    cin >> l >> r >> p;
    
    cout << countValidKeys(l, r, p) << endl;
    return 0;
}