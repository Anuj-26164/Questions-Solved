#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll findKthDivisor(ll n, ll k) {
    if (n <= 0) return -1;
    
    set<ll> divisors;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.insert(i);
            if (i != n/i) {
                divisors.insert(n/i);
            }
        }
    }
    
    if (k <= 0 || k > divisors.size()) return -1;
    
    vector<ll> divs(divisors.begin(), divisors.end());
    return divs[k-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, k, i;
    cin >> n >> k >> i;
    
    ll current = n;
    for (ll iter = 0; iter < i; iter++) {
        current = findKthDivisor(current, k);
        if (current == -1) break;
    }
    
    cout << current << '\n';
    return 0;
}