#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long count = 0;
    long long x = 5;

    while (n / x > 0) {
        count += n / x;
        x *= 5;
    }

    cout << count;
    return 0;
}
