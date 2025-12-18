#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define ll long long int
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> v1(n);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0) {
            v1[i].first = 1; 
        } else {
            v1[i].first = v1[i - 1].second + 1; 
        }
        v1[i].second = v1[i].first + x - 1; 
    }

    int m;
    cin >> m;
    vl v2(m);
    for (auto &c : v2) {
        cin >> c;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v1[j].first <= v2[i] && v2[i] <= v1[n-1].second) {
                cout << j + 1 << nl; 
                break;
            }
        }
    }

    return 0;
}
