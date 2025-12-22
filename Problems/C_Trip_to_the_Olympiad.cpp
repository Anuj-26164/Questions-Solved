#include <bits/stdc++.h>
using namespace std;

int main() {
    int nt;
    cin >> nt;
    while (nt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        map<int, int> cnts;
        for (int v : a) {
            cnts[v]++;
        }

        vector<pair<int, int>> helper;
        for (auto e : cnts) {
            helper.push_back({e.second, e.first});
        }

        sort(helper.begin(), helper.end());

        int answer = (int)helper.size();
        int remaining = k;

        for (int i = 0; i < (int)helper.size(); ++i) {
            if (helper[i].first > remaining) {
                break;
            }
            remaining -= helper[i].first;
            answer--;
        }

        if (remaining >= helper.back().first) { 
            answer = 1; 
        }

        cout << answer << endl;
    }
    return 0;
}