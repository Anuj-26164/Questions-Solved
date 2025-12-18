#include <bits/stdc++.h>
using namespace std;

#define vl vector<long long>
#define pb push_back
#define ll long long int
#define forl for (int i = 0; i < n; i++)
#define nl '\n'

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vl vec1(n);
        for (auto &c : vec1) {
            cin >> c;
        }
        
        unordered_map<ll, ll> x, y;
        x[0] = 1;
        
        forl {
            long long alpha = vec1[i];
            long long beta = (x[alpha] + y[alpha]) % MOD;
            unordered_map<ll, ll> xx, yy;
            
            if (beta > 0)
                xx[alpha] = beta;
            
            for (auto &[l, c] : x)
                yy[l + 1] = (yy[l + 1] + c) % MOD;
            
            x = move(xx);
            y = move(yy);
        }

        long long test = 0;
        for (auto &[lambda, phi] : x)
            test = (test + phi) % MOD;
        
        for (auto &[lambda, phi] : y)
            test = (test + phi) % MOD;
        
        cout << test << nl;
    }

    return 0;
}
