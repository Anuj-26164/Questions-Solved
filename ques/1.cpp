#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<long long>
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vl a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // Indices [l, r] are 1-based, adjust to 0-based
        l -= 1; 
        r -= 1;

        // Divide into inside and outside segments
        vl inside(a.begin() + l, a.begin() + r + 1);
        vl outside;
        outside.insert(outside.end(), a.begin(), a.begin() + l);
        outside.insert(outside.end(), a.begin() + r + 1, a.end());

        // Sort inside descending and outside ascending
        sort(inside.rbegin(), inside.rend());
        sort(outside.begin(), outside.end());

        // Perform swaps to minimize the segment sum
        int swaps = min(inside.size(), outside.size());
        for (int i = 0; i < swaps; ++i) {
            if (inside[i] > outside[i]) {
                swap(inside[i], outside[i]);
            } else {
                break;
            }
        }

        // Compute the new sum of the segment
        ll segment_sum = accumulate(inside.begin(), inside.end(), 0LL);
        cout << segment_sum << nl;
    }

    return 0;
}
