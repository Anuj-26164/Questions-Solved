#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxPleasure(vector<int>& a) {
    int n = a.size();
    int gcd_val = 0;
    
    for (int i = 1; i < n; ++i) {
        gcd_val = __gcd(gcd_val, a[i] - a[0]);
    }
    
    return gcd_val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        cout << findMaxPleasure(a) << "\n";
    }
    
    return 0;
}
