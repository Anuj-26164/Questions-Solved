#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 100005;

int fact[MAXN], invFact[MAXN];

// Fast exponentiation for modular inverse
int power(int base, int exp, int mod) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Precompute factorials and modular inverses
void precomputeFactorials(int n, int mod) {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invFact[n] = power(fact[n], mod - 2, mod);
    for (int i = n - 1; i > 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

// Compute nCr % mod
int nCr(int n, int r, int mod) {
    if (r > n || r < 0) return 0;
    return ((fact[n] * invFact[r]) % mod * invFact[n - r]) % mod;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());  // Sorting for optimal sequence

    vector<int> amazing_k;
    
    // Precompute factorials for combinatorics
    precomputeFactorials(n, p);

    int minK = a[0] - n + 1;  // The minimum k that makes sense
    for (int k = max(1LL, minK); k <= a.back(); k++) {
        int ludo = k, count = 0;
        
        for (int i = 0; i < n; i++) {
            if (ludo < a[i]) break;
            ludo++;
            count++;
        }

        // g(k) is the number of valid permutations
        int g_k = nCr(n, count, p);

        if (g_k % p != 0) {
            amazing_k.push_back(k);
        }
    }

    cout << amazing_k.size() << "\n";
    for (int k : amazing_k) cout << k << " ";
    cout << "\n";

    return 0;
}
