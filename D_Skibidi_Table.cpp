#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll getNumber(ll n, ll x, ll y) {
    if (n == 1) { 
        if (x == 1 && y == 1) return 1;
        if (x == 1 && y == 2) return 4;
        if (x == 2 && y == 1) return 3;
        if (x == 2 && y == 2) return 2;
    }
    
    ll size = 1LL << (n - 1); 
    ll block = size * size;  
    ll half = size;
    
    if (x <= half && y <= half) { 
        return getNumber(n - 1, x, y);
    } else if (x > half && y > half) { 
        ll dx = x - half, dy = y - half;
        return block + getNumber(n - 1, dx, dy);
    } else if (x > half && y <= half) { 
        ll dx = x - half, dy = y;
        return 2 * block + getNumber(n - 1, dx, dy);
    } else { 
        ll dx = x, dy = y - half;
        return 3 * block + getNumber(n - 1, dx, dy);
    }
}


pair<ll, ll> getPosition(ll n, ll d) {
    if (n == 1) {
        if (d == 1) return {1, 1};
        if (d == 2) return {2, 2};
        if (d == 3) return {2, 1};
        if (d == 4) return {1, 2};
    }
    
    ll size = 1LL << (n - 1);
    ll block = size * size;
    
    if (d <= block) {
        auto [px, py] = getPosition(n - 1, d);
        return {px, py};
    } else if (d <= 2 * block) { 
        auto [px, py] = getPosition(n - 1, d - block);
        return {px + size, py + size};
    } else if (d <= 3 * block) { 
        auto [px, py] = getPosition(n - 1, d - 2 * block);
        return {px + size, py};
    } else { 
        auto [px, py] = getPosition(n - 1, d - 3 * block);
        return {px, py + size};
    }
}

void solve() {
    ll n, q;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        string type;
        cin >> type;
        if (type == "->") {
            ll x, y;
            cin >> x >> y;
            cout << getNumber(n, x, y) << "\n";
        } else { // "<-"
            ll d;
            cin >> d;
            auto [x, y] = getPosition(n, d);
            cout << x << " " << y << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    return 0;
}