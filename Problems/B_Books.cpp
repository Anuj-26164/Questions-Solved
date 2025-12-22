#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vl arr(n);
    for (auto &c : arr) cin >> c;

    ll sum = 0, maxcount = 0, count = 0;
    int start = 0;
    for (int end = 0; end < n; ++end) {
        sum += arr[end];
        count++;
        while (sum > k) {
            sum -= arr[start];
            start++;
            count--;
        }
        maxcount = max(maxcount, count);
    }

    cout << maxcount << '\n';
    return 0;
}
