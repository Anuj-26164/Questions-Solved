#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sizes(n + 1); // Initialize the vector with size n+1 for 1-based indexing
    unordered_set<int> ssizes;

    for (int i = 1; i <= n; i++) {
        cin >> sizes[i];
        ssizes.insert(sizes[i]);
    }

    for (int a = 1; a < n; a++) {
        for (int b = a + 1; b <= n; b++) {
            int sum = sizes[a] + sizes[b];
            if (ssizes.find(sum) != ssizes.end()) {
                for (int k = 1; k <= n; k++) {
                    if (sizes[k] == sum && k != a && k != b) {
                        cout << a << " " << b << " " << k << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << -1 << endl;
return 0;
}