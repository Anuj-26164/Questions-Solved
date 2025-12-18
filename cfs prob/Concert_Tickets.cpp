#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, m;
    cin >> n >> m;
    
    multiset<ll> tickets;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        tickets.insert(x);
    }
    
    for (ll i = 0; i < m; i++) {
        ll price;
        cin >> price;
        auto it = tickets.upper_bound(price);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            --it; 
            cout << *it << '\n';
            tickets.erase(it);  
        }
    }
    
    return 0;
}
