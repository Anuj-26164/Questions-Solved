#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define nl '\n'
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> vec;
 
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            ll rem = x % k;
            vec.push_back({rem == 0 ? k : rem, i + 1});
        }
 
        sort(vec.begin(), vec.end(), [](pair<ll, ll> &a, pair<ll, ll> &b) {
            return (a.first == b.first) ? (a.second < b.second) : (a.first > b.first);
        });
 
        for (auto &[_, idx] : vec) {
            cout << idx << " ";
        }
        cout << nl;
    }
    return 0;
}