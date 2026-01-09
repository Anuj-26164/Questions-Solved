#include <bits/stdc++.h>
using namespace std;

int main() {
    // What is the 10001st prime number?
    vector<int> primes;
    int n = 2;
    while (primes.size() < 10001) {
        bool is_prime = true;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(n);
        }
        n++;
    }
    cout << primes[primes.size() - 1] << "\n";
    return 0;
}