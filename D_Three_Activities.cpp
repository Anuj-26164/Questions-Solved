#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define ll long long int
#define f(k, n) for (int i = k; i < n; i++)
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        
        set<pair<ll, ll>> st1, st2, st3;
        
        f(0, n) {
            ll x;
            cin >> x;
            st1.insert({x, i});
        }
        f(0, n) {
            ll x;
            cin >> x;
            st2.insert({x, i});
        }
        f(0, n) {
            ll x;
            cin >> x;
            st3.insert({x, i});
        }

        vector<pair<ll, ll>> v1(st1.rbegin(), next(st1.rbegin(), min(3, (int)st1.size())));
        vector<pair<ll, ll>> v2(st2.rbegin(), next(st2.rbegin(), min(3, (int)st2.size())));
        vector<pair<ll, ll>> v3(st3.rbegin(), next(st3.rbegin(), min(3, (int)st3.size())));

        ll max_sum = 0;
        
        for (auto [a1, i1] : v1) {
            for (auto [a2, i2] : v2) {
                if (i1 == i2) continue;
                for (auto [a3, i3] : v3) {
                    if (i1 != i3 && i2 != i3) {
                        max_sum = max(max_sum, a1 + a2 + a3);
                    }
                }
            }
        }

        cout << max_sum << nl;
    }
    return 0;
}
