#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

// Fast Exponentiation by Squaring
int power2(int n) {
    if (n == 0) return 1; // Base case: 2^0 = 1
    long long half = power2(n / 2);
    long long result = (half * half) % M;
    if (n % 2 != 0) result = (result * 2) % M; // If n is odd
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << power2(n) << endl;
    return 0;
}
