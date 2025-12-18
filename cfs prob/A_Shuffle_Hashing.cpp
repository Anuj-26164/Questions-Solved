#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")

#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string p, h;
        cin >> p >> h;

        vector<int> alpha(26, 0);
        for (char c : p) {
            alpha[c - 'a']++;
        }
        if (p.size() > h.size()) {
            cout << "NO" << nl;
            continue;
        }
        vector<int> beta(26, 0);
        for (int i = 0; i < p.size(); i++) {
            beta[h[i] - 'a']++;
        }
        if (alpha == beta) {
            cout << "YES" << nl;
            continue;
        }

        for (int i = p.size(); i < h.size(); i++) {
            beta[h[i] - 'a']++;         
            beta[h[i - p.size()] - 'a']--;

            if (alpha == beta) { 
                cout << "YES" << nl;
                goto next_case;
            }
        }

        cout << "NO" << nl; 
    next_case:
        continue;
    }

    return 0;
}
