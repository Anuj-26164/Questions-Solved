#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s, ans;
        cin >> s;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == 'p') {
                ans += 'q';
            } else if (s[i] == 'q') {
                ans += 'p';
            } else if (s[i] == 'w') {
                ans += 'w';
            } else {
                ans += '?'; 
            }
        }
        cout << ans << nl;
    }
    return 0;
}
